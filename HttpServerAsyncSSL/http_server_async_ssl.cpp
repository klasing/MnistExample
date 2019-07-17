// http_server_async_ssl.cpp
// Taken from:
// https://www.boost.org/doc/libs/1_70_0/libs/beast/example/http/server/async/http_server_async.cpp
// and from:
// https://www.boost.org/doc/libs/1_70_0/libs/beast/example/http/server/async-ssl/http_server_async_ssl.cpp
#define _WIN32_WINNT 0x0601

//#include "server_certificate.hpp"
#include "server_certificate_new.hpp"

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/strand.hpp>
#include <boost/config.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include "SmtpClient.cpp"
#include "Connect2SQLite.hpp"
#include "HandlerForLogin.hpp"
#include "HandlerForRegister.hpp"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
namespace ssl = boost::asio::ssl;		// from <boost/asio/ssl.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
namespace ns_http_server_async_ssl {
	const int SECONDS_BEFORE_EXPIRING = 300;
	//***************************************************************************
	//*                    mime_type
	//***************************************************************************
	// Return a reasonable mime type based on the extension of a file.
	inline beast::string_view
		mime_type(beast::string_view path)
	{
		using beast::iequals;
		auto const ext = [&path]
		{
			auto const pos = path.rfind(".");
			if (pos == beast::string_view::npos)
				return beast::string_view{};
			return path.substr(pos);
		}();
		if (iequals(ext, ".htm"))  return "text/html";
		if (iequals(ext, ".html")) return "text/html";
		if (iequals(ext, ".php"))  return "text/html";
		if (iequals(ext, ".css"))  return "text/css";
		if (iequals(ext, ".txt"))  return "text/plain";
		if (iequals(ext, ".js"))   return "application/javascript";
		if (iequals(ext, ".json")) return "application/json";
		if (iequals(ext, ".xml"))  return "application/xml";
		if (iequals(ext, ".swf"))  return "application/x-shockwave-flash";
		if (iequals(ext, ".flv"))  return "video/x-flv";
		if (iequals(ext, ".png"))  return "image/png";
		if (iequals(ext, ".jpe"))  return "image/jpeg";
		if (iequals(ext, ".jpeg")) return "image/jpeg";
		if (iequals(ext, ".jpg"))  return "image/jpeg";
		if (iequals(ext, ".gif"))  return "image/gif";
		if (iequals(ext, ".bmp"))  return "image/bmp";
		if (iequals(ext, ".ico"))  return "image/vnd.microsoft.icon";
		if (iequals(ext, ".tiff")) return "image/tiff";
		if (iequals(ext, ".tif"))  return "image/tiff";
		if (iequals(ext, ".svg"))  return "image/svg+xml";
		if (iequals(ext, ".svgz")) return "image/svg+xml";
		return "application/text";
	}

	//***************************************************************************
	//*                    path_cat
	//***************************************************************************
	// Append an HTTP rel-path to a local filesystem path.
	// The returned path is normalized for the platform.
	inline std::string
		path_cat(
			beast::string_view base,
			beast::string_view path)
	{
		if (base.empty())
			return std::string(path);
		std::string result(base);
#ifdef BOOST_MSVC
		char constexpr path_separator = '\\';
		if (result.back() == path_separator)
			result.resize(result.size() - 1);
		result.append(path.data(), path.size());
		for (auto& c : result)
			if (c == '/')
				c = path_separator;
#else
		char constexpr path_separator = '/';
		if (result.back() == path_separator)
			result.resize(result.size() - 1);
		result.append(path.data(), path.size());
#endif
		return result;
	}

	//***************************************************************************
	//*                    filter_target_email_and_password_and_code
	//***************************************************************************
	template<
		class Body, class Allocator>
		inline void 
			filter_target_email_and_password_and_code(
				http::request<Body, http::basic_fields<Allocator>> req,
				std::string& target,
				std::string& user_email_address,
				std::string& user_password,
				std::string& user_code)
	{
		// filter target
		target = static_cast<std::string>(req.target());

		std::string payload = req.body();
		// filter user_email_address
		size_t sBegin = 0, sEnd = 0, sLength = 0, sTemp;
		sTemp = 0;
		sBegin = payload.find_first_of("=", sTemp);
		sEnd = (payload.find("&", sBegin) != std::string::npos) ?
			(payload.find("&", sBegin) - 1) :
			payload.length() - 1;
		sLength = sEnd - sBegin;
		sBegin++;
		user_email_address = payload.substr(sBegin, sLength);
		// filter user_password
		sTemp = sEnd;
		sBegin = payload.find_first_of("=", sTemp);
		sEnd = (payload.find("&", sBegin) != std::string::npos) ?
			(payload.find("&", sBegin) - 1) :
			payload.length() - 1;
		sLength = sEnd - sBegin;
		sBegin++;
		user_password = payload.substr(sBegin, sLength);
		// filter user_code
		sTemp = sEnd;
		sBegin = payload.find_first_of("=", sTemp);
		if (sBegin == std::string::npos)
			// no user code available
			return;
		sEnd = (payload.find("&", sBegin) != std::string::npos) ?
			(payload.find("&", sBegin) - 1) :
			payload.length() - 1;
		sLength = sEnd - sBegin;
		sBegin++;
		user_code = payload.substr(sBegin, sLength);
	}
	
	//***************************************************************************
	//*                    handle_request
	//***************************************************************************
	// This function produces an HTTP response for the given
	// request. The type of the response object depends on the
	// contents of the request, so the interface requires the
	// caller to pass a generic lambda for receiving the response.
	template<
		class Body, class Allocator,
		class Send>
		void
		handle_request(
			beast::string_view doc_root,
			std::shared_ptr<Connect2SQLite> pSqlite,
			std::shared_ptr<HandlerForRegister> pHandlerForRegister,
			http::request<Body, http::basic_fields<Allocator>>&& req,
			Send&& send)
	{
		// Returns a bad request response
		auto const bad_request =
			[&req](beast::string_view why)
		{
			http::response<http::string_body> res{ http::status::bad_request, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, "text/html");
			res.keep_alive(req.keep_alive());
			res.body() = std::string(why);
			res.prepare_payload();
			return res;
		};

		// Returns a not found response
		auto const not_found =
			[&req](beast::string_view target)
		{
			http::response<http::string_body> res{ http::status::not_found, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, "text/html");
			res.keep_alive(req.keep_alive());
			res.body() = "The resource '" + std::string(target) + "' was not found.";
			res.prepare_payload();
			return res;
		};

		// Returns a server error response
		auto const server_error =
			[&req](beast::string_view what)
		{
			http::response<http::string_body> res{ http::status::internal_server_error, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, "text/html");
			res.keep_alive(req.keep_alive());
			res.body() = "An error occurred: '" + std::string(what) + "'";
			res.prepare_payload();
			return res;
		};

		// Make sure we can handle the method
		if (req.method() != http::verb::post && 
			req.method() != http::verb::get &&
			req.method() != http::verb::put &&
			req.method() != http::verb::head)
			return send(bad_request("Unknown HTTP-method"));

		// Request path must be absolute and not contain "..".
		if (req.target().empty() ||
			req.target()[0] != '/' ||
			req.target().find("..") != beast::string_view::npos)
			return send(bad_request("Illegal request-target"));

//////////////////////////////////////////////////////////////////////////////
		// Respond to a POST request
		if (req.method() == http::verb::post) {
			std::cout << "-> POST message received" << std::endl;
			//std::string payload = req.body();
			std::string target = "";
			std::string user_email_address = "";
			std::string user_password = "";
			std::string user_code = "";
			filter_target_email_and_password_and_code(
				req,
				target,
				user_email_address,
				user_password,
				user_code);
			std::cout 
				<< target << " " 
				<< user_email_address << " " 
				<< user_password << " "
				<< user_code
				<< std::endl;

			std::string response_payload = target + ": ";
			response_payload.erase(0, 1);

			if (target == "/login") {
				HandlerForLogin handlerForlogin;
				handlerForlogin.handle_login(
					user_email_address,
					user_password,
					pSqlite,
					response_payload);
			}
			if (target == "/register") {
				//HandlerForRegister handlerForRegister;
				pHandlerForRegister->handle_register(
					user_email_address,
					user_password,
					pSqlite,
					response_payload);
			}
			if (target == "/register_confirm") {
				//HandlerForRegister handlerForRegister;
				pHandlerForRegister->handle_register_confirm(
					user_email_address,
					user_password,
					user_code,
					pSqlite,
					response_payload);
			}

			http::response<http::string_body> res{
				http::status::ok, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, "text/html");
			res.body() = response_payload;
			res.prepare_payload();
			res.keep_alive(req.keep_alive());

			return send(std::move(res));
		}
//////////////////////////////////////////////////////////////////////////////

		if (req.method() == http::verb::get ||
			req.method() == http::verb::head) {
			// Build the path to the requested file
			std::string path = path_cat(doc_root, req.target());
			if (req.target().back() == '/')
				// the default file for download when no file name 
				// is given from the client
				path.append("index.html");

			// Attempt to open the file
			beast::error_code ec;
			http::file_body::value_type body;
			body.open(path.c_str(), beast::file_mode::scan, ec);

			// Handle the case where the file doesn't exist
			if (ec == beast::errc::no_such_file_or_directory)
				return send(not_found(req.target()));

			// Handle an unknown error
			if (ec)
				return send(server_error(ec.message()));

			// Cache the size since we need it after the move
			auto const size = body.size();

			// Respond to HEAD request
			if (req.method() == http::verb::head)
			{
				http::response<http::empty_body> res{ http::status::ok, req.version() };
				res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
				res.set(http::field::content_type, mime_type(path));
				res.content_length(size);
				res.keep_alive(req.keep_alive());
				return send(std::move(res));
			}

			// Respond to GET request
			http::response<http::file_body> res{
				std::piecewise_construct,
				std::make_tuple(std::move(body)),
				std::make_tuple(http::status::ok, req.version()) };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, mime_type(path));
			res.content_length(size);
			res.keep_alive(req.keep_alive());
			return send(std::move(res));
		}


		// Respond to a PUT request
		if (req.method() == http::verb::put) {
			std::cout << "-> PUT message received" << std::endl;
			// used with experimental
			//std::cout << "-> Body: " << req[http::field::body] << std::endl;
			std::cout << "-> File: " << req.target() << std::endl;
			// https://github.com/boostorg/beast/issues/819
			std::cout << "-> Message: " << std::endl;
			std::cout << req << std::endl;

			// Store the received file on disk
			std::string file_destination_ = static_cast<std::string>(req.target());
			// remove the forward slash
			file_destination_.erase(0, 1);
			boost::filesystem::path p{ file_destination_ };
			boost::filesystem::ofstream ofs{ p };
			// remove all the \r-characters (return) from the payload
			boost::erase_all(req.body(), "\r");
			ofs << req.body();

			http::response<http::string_body> res{
				http::status::ok, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.keep_alive(req.keep_alive());
			return send(std::move(res));
		}
	}

	//***************************************************************************
	//*                    fail
	//***************************************************************************
	// Report a failure
	inline void
		fail(beast::error_code ec, char const* what)
	{
		std::cerr << what << ": " << ec.message() << "\n";
	}

	//***************************************************************************
	//*                    session
	//***************************************************************************
	// Handles an HTTP server connection
	class session : public std::enable_shared_from_this<session>
	{
		// This is the C++11 equivalent of a generic lambda.
		// The function object is used to send an HTTP message.
		struct send_lambda
		{
			session& self_;

			explicit
				send_lambda(session& self)
				: self_(self)
			{
			}

			template<bool isRequest, class Body, class Fields>
			void
				operator()(http::message<isRequest, Body, Fields>&& msg) const
			{
				// The lifetime of the message has to extend
				// for the duration of the async operation so
				// we use a shared_ptr to manage it.
				auto sp = std::make_shared<
					http::message<isRequest, Body, Fields>>(std::move(msg));

				// Store a type-erased version of the shared
				// pointer in the class to keep it alive.
				self_.res_ = sp;

				// Write the response
				http::async_write(
					self_.stream_,
					*sp,
					beast::bind_front_handler(
						&session::on_write,
						self_.shared_from_this(),
						sp->need_eof()));
			}
		};

		beast::ssl_stream<beast::tcp_stream> stream_;
		beast::flat_buffer buffer_;
		std::shared_ptr<std::string const> doc_root_;
		std::shared_ptr<Connect2SQLite> pSqlite_;
		std::shared_ptr<HandlerForRegister> pHandlerForRegister_;
		http::request<http::string_body> req_;
		std::shared_ptr<void> res_;
		send_lambda lambda_;

	public:
		// Take ownership of the stream
		explicit
		session(
			tcp::socket&& socket,
			ssl::context& ctx,
			std::shared_ptr<std::string const> const& doc_root,
			std::shared_ptr<Connect2SQLite> const& pSqlite,
			std::shared_ptr<HandlerForRegister> const& pHandlerForRegister)
			: stream_(std::move(socket), ctx)
			, doc_root_(doc_root)
			, pSqlite_(pSqlite)
			, pHandlerForRegister_(pHandlerForRegister)
			, lambda_(*this)
		{
			std::cout << "<<constructor>> session()" << std::endl;
		}

		// Start the asynchronous operation
		void
			run()
		{
			// Set the timeout.
			//beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(30));
			beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(
				SECONDS_BEFORE_EXPIRING));

			// Perform the SSL handshake
			stream_.async_handshake(
				ssl::stream_base::server,
				beast::bind_front_handler(
					&session::on_handshake,
					shared_from_this()));
		}

		void
			on_handshake(beast::error_code ec)
		{
			if (ec)
				return fail(ec, "handshake");

			do_read();
		}

		void
			do_read()
		{
			// Make the request empty before reading,
			// otherwise the operation behavior is undefined.
			req_ = {};

			// Set the timeout.
			//beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(30));
			beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(
				SECONDS_BEFORE_EXPIRING));

			// Read a request
			http::async_read(stream_, buffer_, req_,
				beast::bind_front_handler(
					&session::on_read,
					shared_from_this()));
		}

		void
			on_read(
				beast::error_code ec,
				std::size_t bytes_transferred)
		{
			boost::ignore_unused(bytes_transferred);

			// This means they closed the connection
			if (ec == http::error::end_of_stream)
				return do_close();

			if (ec)
				return fail(ec, "read");

			// Send the response
			handle_request(*doc_root_ 
				, pSqlite_
				, pHandlerForRegister_
				, std::move(req_) 
				, lambda_);
		}

		void
			on_write(
				bool close,
				beast::error_code ec,
				std::size_t bytes_transferred)
		{
			boost::ignore_unused(bytes_transferred);

			if (ec)
				return fail(ec, "write");

			if (close)
			{
				// This means we should close the connection, usually because
				// the response indicated the "Connection: close" semantic.
				return do_close();
			}

			// We're done with the response so delete it
			res_ = nullptr;

			// Read another request
			do_read();
		}

		void
			do_close()
		{
			// Set the timeout.
			//beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(30));
			beast::get_lowest_layer(stream_).expires_after(std::chrono::seconds(
				SECONDS_BEFORE_EXPIRING));

			// Perform the SSL shutdown
			stream_.async_shutdown(
				beast::bind_front_handler(
					&session::on_shutdown,
					shared_from_this()));
		}

		void
			on_shutdown(beast::error_code ec)
		{
			if (ec)
				return fail(ec, "shutdown");

			// At this point the connection is closed gracefully
		}
	};

	//***************************************************************************
	//*                    listener
	//***************************************************************************
	// Accepts incoming connections and launches the sessions
	class listener : public std::enable_shared_from_this<listener>
	{
		net::io_context& ioc_;
		ssl::context& ctx_;
		tcp::acceptor acceptor_;
		std::shared_ptr<std::string const> doc_root_;
		std::shared_ptr<Connect2SQLite> pSqlite_;
		std::shared_ptr<HandlerForRegister> pHandlerForRegister_;

	public:
		listener(
			net::io_context& ioc,
			ssl::context& ctx,
			tcp::endpoint endpoint,
			std::shared_ptr<std::string const> const& doc_root,
			std::shared_ptr<Connect2SQLite> const& pSqlite)
			: ioc_(ioc)
			, ctx_(ctx)
			, acceptor_(net::make_strand(ioc))
			, doc_root_(doc_root)
			, pSqlite_(pSqlite)
		{
			std::cout << "<<constructor>> listener()" << std::endl;
			HandlerForRegister oHandlerForRegister;
			pHandlerForRegister_ =
				std::make_shared<HandlerForRegister>(oHandlerForRegister);

			beast::error_code ec;

			// Open the acceptor
			acceptor_.open(endpoint.protocol(), ec);
			if (ec)
			{
				fail(ec, "open");
				return;
			}

			// Allow address reuse
			acceptor_.set_option(net::socket_base::reuse_address(true), ec);
			if (ec)
			{
				fail(ec, "set_option");
				return;
			}

			// Bind to the server address
			acceptor_.bind(endpoint, ec);
			if (ec)
			{
				fail(ec, "bind");
				return;
			}

			// Start listening for connections
			acceptor_.listen(
				net::socket_base::max_listen_connections, ec);
			if (ec)
			{
				fail(ec, "listen");
				return;
			}
		}

		// Start accepting incoming connections
		void
			run()
		{
			do_accept();
		}

	private:
		void
			do_accept()
		{
			// The new connection gets its own strand
			acceptor_.async_accept(
				net::make_strand(ioc_),
				beast::bind_front_handler(
					&listener::on_accept,
					shared_from_this()));
		}

		void
			on_accept(beast::error_code ec, tcp::socket socket)
		{
			std::string remote_endpoint = boost::lexical_cast<std::string>(socket.remote_endpoint());
			std::cout << "Remote endpoint " << remote_endpoint.c_str() << std::endl;

			if (ec)
			{
				fail(ec, "accept");
			}
			else
			{
				// Create the session and run it
				std::make_shared<session>(
					std::move(socket),
					ctx_,
					doc_root_,
					pSqlite_,
					pHandlerForRegister_)->run();
			}

			// Accept another connection
			do_accept();
		}
	};

	//***************************************************************************
	//*                    http_server_async_ssl
	//***************************************************************************
	inline int http_server_async_ssl(int argc, char* argv[])
	{
		// Check command line arguments.
		if (argc != 5)
		{
			std::cerr <<
				"Usage: http-server-async-ssl <address> <port> <doc_root> <threads>\n" <<
				"Example:\n" <<
				"    http-server-async 0.0.0.0 8080 . 1\n";
			return EXIT_FAILURE;
		}
		auto const address = net::ip::make_address(argv[1]);
		auto const port = static_cast<unsigned short>(std::atoi(argv[2]));
		auto const doc_root = std::make_shared<std::string>(argv[3]);
		auto const threads = std::max<int>(1, std::atoi(argv[4]));

		// create a database object for the entire duration of the
		// server instance
		Connect2SQLite oSqlite;
		// open database
		oSqlite.openDb();
		oSqlite.createTable();
		// will create an error message when the default user already exists
		// SQL error: UNIQUE constraint failed: 
		// user_access_login_data.user_email_address
		oSqlite.insertDefaultUser();
		// create pointer to the Connect2SQLite instance
		auto const pSqlite =
			 std::make_shared<Connect2SQLite>(oSqlite);

		// The io_context is required for all I/O
		net::io_context ioc{ threads };

		// The SSL context is required, and holds certificates
		ssl::context ctx{ ssl::context::tlsv12 };

		// This holds the self-signed certificate used by the server
		load_server_certificate(ctx);

		// Create and launch a listening port
		std::make_shared<listener>(
			ioc,
			ctx,
			tcp::endpoint{ address, port },
			doc_root,
			pSqlite)->run();

		// Run the I/O service on the requested number of threads
		std::vector<std::thread> v;
		v.reserve(threads - 1);
		for (auto i = threads - 1; i > 0; --i)
			v.emplace_back(
				[&ioc]
		{
			ioc.run();
		});
		ioc.run();

		// close database
		oSqlite.closeDb();

		return EXIT_SUCCESS;
	}
}
