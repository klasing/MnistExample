#define _WIN32_WINNT 0x0601

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/strand.hpp>
#include <boost/filesystem/fstream.hpp>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

//***************************************************************************
//*                    prototype
//***************************************************************************
void set_logged_in(const bool&);
void get_confirmation_code();

//***************************************************************************
//*                    global
//***************************************************************************
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

//****************************************************************************
//*                     fail
//****************************************************************************
inline void
fail(beast::error_code ec, char const* what)
{
	std::cerr << what << ": " << ec.message() << "\n";
}

//****************************************************************************
//*                     session
//****************************************************************************
// Performs an HTTP GET and prints the response
class session : public std::enable_shared_from_this<session>
{
	tcp::resolver resolver_;
	beast::tcp_stream stream_;
	beast::flat_buffer buffer_; // (Must persist between reads)
	//http::request<http::empty_body> req_;
	http::request<http::empty_body> req_with_empty_body_;
	http::request<http::string_body> req_with_string_body_;
	http::request<http::file_body> req_with_file_body_;
	http::response<http::string_body> res_;
	std::string mode_;
	std::string user_email_address_;
	std::string user_password_;
	std::string payload_;
	std::string file_name_on_server_;
	std::string file_name_on_client_;
	std::string target_;
	std::string host_;
	std::string port_;
	int version_;
	std::shared_ptr<std::string const> doc_root_;

public:
	// Objects are constructed with a strand to
	// ensure that handlers do not execute concurrently.
	explicit
		session(net::io_context& ioc)
		: resolver_(net::make_strand(ioc))
		, stream_(net::make_strand(ioc))
	{
		std::cout << "<<constructor>> session()\n";
		doc_root_ = std::make_shared<std::string>("./user_space");
	}

	// Start the asynchronous operation
	void
		run(
			char const* mode,
			char const* user_email_address,
			char const* user_password,
			char const* payload,
			char const* file_name_on_server,
			char const* file_name_on_client,
			char const* target,
			char const* host,
			char const* port,
			int version)
	{
		mode_ = mode;
		user_email_address_ = user_email_address;
		user_password_ = user_password;
		payload_ = payload;
		file_name_on_server_ = "/" + std::string(file_name_on_server);
		file_name_on_client_ = file_name_on_client;
		target_ = target;
		host_ = host;
		port_ = port;
		version_ = version;

		// Set up an HTTP GET request message
		//req_.version(version);
		//req_.method(http::verb::get);
		//req_.target(target);
		//req_.set(http::field::host, host);
		//req_.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		if (mode_ == "trace")
		{
			// Set up an HTTP TRACE request message
			req_with_empty_body_.version(version_);
			req_with_empty_body_.method(http::verb::trace);
			req_with_empty_body_.target(target_);
			req_with_empty_body_.set(http::field::host, host_);
			req_with_empty_body_.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
		}

		if (mode_ == "access")
		{
			// prepare payload
			http::string_body::value_type body;
			body = payload_;
			auto size = payload_.length();

			// Set up an HTTP POST request message
			req_with_string_body_.method(http::verb::post);
			req_with_string_body_.target(target_);
			req_with_string_body_.version(version_);
			req_with_string_body_.set(http::field::host, host_);
			req_with_string_body_.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
			req_with_string_body_.set(http::field::content_type, "application/x-www-form-urlencoded");
			req_with_string_body_.content_length(size);
			req_with_string_body_.body() = body;
			req_with_string_body_.prepare_payload();
		}

		if (mode_ == "download")
		{
			// Set up an HTTP GET request message
			req_with_empty_body_.version(version_);
			req_with_empty_body_.method(http::verb::get);
			req_with_empty_body_.target(file_name_on_server_); //req_with_empty_body_.target(target_);
			req_with_empty_body_.set(http::field::host, host_);
			req_with_empty_body_.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
		}

		if (mode_ == "upload")
		{
			// Attempt to open the file
			beast::error_code ec;
			http::file_body::value_type body;
			body.open(file_name_on_client_.c_str(), beast::file_mode::scan, ec);

			// Handle the case where the file doesn't exist
			if (ec == beast::errc::no_such_file_or_directory) {
				std::cout << file_name_on_client_.c_str() << " not found" << std::endl;
				return;
			}

			// Handle an unknown error
			if (ec)
				std::cout << "Error: " << ec.message() << std::endl;

			// Cache the size since we need it after the move
			auto const size = body.size();

			// Build the path to the requested file
			std::string path = path_cat(*doc_root_, file_name_on_client_.c_str());

			// Set up an HTTP PUT request message
			req_with_file_body_.method(http::verb::put);
			req_with_file_body_.target(file_name_on_server_);
			req_with_file_body_.version(version_);
			req_with_file_body_.set(http::field::host, host_);
			req_with_file_body_.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
			req_with_file_body_.set(http::field::content_type, mime_type(path));
			req_with_file_body_.content_length(size);
			req_with_file_body_.body() = std::move(body);
			req_with_file_body_.prepare_payload();
		}

		// Look up the domain name
		resolver_.async_resolve(
			host_,
			port_,
			beast::bind_front_handler(
				&session::on_resolve,
				shared_from_this()));
	}

	void
		on_resolve(
			beast::error_code ec,
			tcp::resolver::results_type results)
	{
		if (ec)
			return fail(ec, "resolve");

		// Set a timeout on the operation
		stream_.expires_after(std::chrono::seconds(SECONDS_BEFORE_EXPIRING));

		// Make the connection on the IP address we get from a lookup
		stream_.async_connect(
			results,
			beast::bind_front_handler(
				&session::on_connect,
				shared_from_this()));
	}

	void
		on_connect(beast::error_code ec, tcp::resolver::results_type::endpoint_type)
	{
		if (ec)
			return fail(ec, "connect");

		// Set a timeout on the operation
		stream_.expires_after(std::chrono::seconds(SECONDS_BEFORE_EXPIRING));

		// Send the HTTP request to the remote host
		//http::async_write(stream_, req_,
		//	beast::bind_front_handler(
		//		&session::on_write,
		//		shared_from_this()));

		// Send the HTTP request to the remote host
		if (mode_ == "trace" || mode_ == "download")
		{
			http::async_write(stream_, req_with_empty_body_,
				beast::bind_front_handler(
					&session::on_write,
					shared_from_this()));
		}
		if (mode_ == "access")
		{
			http::async_write(stream_, req_with_string_body_,
				beast::bind_front_handler(
					&session::on_write,
					shared_from_this()));
		}
		if (mode_ == "upload")
		{
			http::async_write(stream_, req_with_file_body_,
				beast::bind_front_handler(
					&session::on_write,
					shared_from_this()));
		}
	}

	void
		on_write(
			beast::error_code ec,
			std::size_t bytes_transferred)
	{
		boost::ignore_unused(bytes_transferred);

		if (ec)
			return fail(ec, "write");

		// Receive the HTTP response
		http::async_read(stream_, buffer_, res_,
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

		if (ec)
			return fail(ec, "read");

		// Write the message to standard out
		std::cout << res_ << std::endl;

		std::string response_body = res_.body();
		if (response_body == "login: succeeded.")
			set_logged_in(true);

		if (response_body == "register: enter the code received by email." ||
			response_body == "reset_password: enter the code received by email.")
			get_confirmation_code();

		// Store the received file on disk
		if (!std::strcmp("download", mode_.c_str())) {
			boost::filesystem::path p{ file_name_on_client_ };
			boost::filesystem::ofstream ofs{ p };
			ofs << res_.body();
		}

		// Gracefully close the socket
		stream_.socket().shutdown(tcp::socket::shutdown_both, ec);

		// not_connected happens sometimes so don't bother reporting it.
		if (ec && ec != beast::errc::not_connected)
			return fail(ec, "shutdown");

		// If we get here then the connection is closed gracefully
	}
};

//****************************************************************************
//*                     http_client_async
//****************************************************************************
inline int http_client_async(int argc, char** argv)
{
	auto const cmd = argv[0];
	auto const mode = argv[1];
	auto const user_email_address = argv[2];
	auto const user_password = argv[3];
	auto const payload = argv[4];
	auto const file_name_on_server = argv[5];
	auto const file_name_on_client = argv[6];
	auto const target = argv[7];
	auto const host = argv[8];
	auto const port = argv[9];
	int version = argc == 11 && !std::strcmp("1.0", argv[10]) ? 10 : 11;

	// The io_context is required for all I/O
	net::io_context ioc;

	// Launch the asynchronous operation
	std::make_shared<session>(ioc)->run(
		mode,
		user_email_address,
		user_password,
		payload,
		file_name_on_server,
		file_name_on_client,
		target,
		host,
		port,
		version
	);

	// Run the I/O service. The call will return when
	// the get operation is complete.
	ioc.run();

	return EXIT_SUCCESS;
}