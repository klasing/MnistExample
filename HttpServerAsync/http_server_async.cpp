#define _WIN32_WINNT 0x0601

#include <boost/algorithm/string.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/strand.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/config.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include "ServerLogging.cpp"
#include "SmtpClient.cpp"
#include "Connect2SQLite.hpp"
#include "HandlerForLogin.hpp"
#include "HandlerForRegister.hpp"
#include "HandlerForResetPassword.hpp"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

//****************************************************************************
//*                     global
//****************************************************************************
const int SECONDS_BEFORE_EXPIRING = 300;

//****************************************************************************
//*                     prototype
//****************************************************************************
std::string date_for_http_response();

//****************************************************************************
//*                     date_for_http_response
//****************************************************************************
//inline std::string
//date_for_http_response()
//{
//	std::string dow[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
//	std::string month[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
//	time_t tt;
//	time(&tt);
//	tm t;
//	localtime_s(&t, &tt);
//	struct tm gmt;
//	gmtime_s(&gmt, &tt);
//	std::ostringstream oss;
//	oss << dow[gmt.tm_wday] << ", "
//		<< std::setw(2) << std::setfill('0') << gmt.tm_mday << " "
//		<< month[gmt.tm_mon] << " "
//		<< gmt.tm_year + 1900 << " "
//		<< std::setw(2) << std::setfill('0') << gmt.tm_hour << ":"
//		<< std::setw(2) << std::setfill('0') << gmt.tm_min << ":"
//		<< std::setw(2) << std::setfill('0') << gmt.tm_sec << " "
//		<< "GMT";
//	return oss.str();
//}

//****************************************************************************
//*                     mime_type
//****************************************************************************
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

//****************************************************************************
//*                     path_cat
//****************************************************************************
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
//*                    filter_email_password_code
//***************************************************************************
template<class Body, class Allocator>
inline void
filter_email_password_code(
	http::request<Body, http::basic_fields<Allocator>> req,
	std::string& user_email_address,
	std::string& user_password,
	std::string& user_code,
	const std::string& user_agent)
{
	std::string payload = req.body();
	// if user_agent not equals Boost.Beast/248
	// it is a browser request
	//if (user_agent != "Boost.Beast/248");
	// replace %40 for @ in user_email_address
	size_t pos = payload.find("%40", 0);
	if (pos != std::string::npos)
		payload = payload.replace(pos, 3, "@");
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

//****************************************************************************
//*                     write_message_to_string
//****************************************************************************
// used in handling a TRACE request
template <class Message, class DynamicBuffer>
auto
write_message_to_string(
	Message& message,
	DynamicBuffer& dynamic_buffer
) -> void
{
	beast::ostream(dynamic_buffer) << message;
}

//****************************************************************************
//*                     filter_filename_payload_from_form_submit
//****************************************************************************
// browser form submit for a file upload as a POST message 
inline auto
filter_filename_payload_from_form_submit(
	const std::string req_body,
	std::string& file_name,
	std::string& payload
) -> void
{
	int sbegin = 0;
	int send = 0;
	std::string string_to_search_for = "";
	// filter file_name
	// look for: filename="
	string_to_search_for = "filename=\"";
	sbegin = req_body.find(string_to_search_for);
	sbegin += string_to_search_for.length();
	// look for ", starting at the sbegin position
	send = req_body.find("\"", sbegin);
	file_name = req_body.substr(sbegin, send - sbegin);

	// the original payload has additional lines of data
	// which have to be removed

	//------WebKitFormBoundarygQus3BLIAghh6JYQ
	//Content-Disposition: form-data; name="file"; filename="bla.txt"
	//Content-Type: text/plain
	//
	//bla bla
	//------WebKitFormBoundarygQus3BLIAghh6JYQ--

	// copy the request body into the payload, the payload
	// will be searched and edited
	payload = req_body;
	// look for: ------WebKitFormBoundary
	string_to_search_for = "------WebKitFormBoundary";
	send = payload.find(string_to_search_for);
	// remove everything up to the send position
	payload.erase(0, send);
	// look for newline, four times, using sbegin as an offset
	sbegin = 0;
	string_to_search_for = "\n";
	for (int i = 0; i < 4; i++) {
		send = payload.find(string_to_search_for, sbegin);
		sbegin = send + 1;
	}
	// what remains is one newline at the beginning of the payload
	// string, remove this newline character
	payload.erase(0, 1);
	// remove everything up to the sbegin position
	payload.erase(0, send);
	// start at the end of the payload string and
	// look -backwards- for the first newline from the
	// last character -which is a newline- minus one
	send = payload.length() - 2;
	sbegin = payload.rfind(string_to_search_for, send);
	payload.erase(sbegin, send);
}

//****************************************************************************
//*                     save_to_disk
//****************************************************************************
inline auto
save_to_disk(
	const std::string& file_name,
	const std::string& payload
) -> void
{
	// Store the received file on disk
	std::string file_name_on_server =
		std::string("user_space/") +
		file_name;
	boost::filesystem::path p{ file_name_on_server };
	boost::filesystem::ofstream ofs{ p };
	ofs << payload;
}

//****************************************************************************
//*                     handle_request
//****************************************************************************
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
		std::shared_ptr<HandlerForResetPassword> pHandlerForResetPassword,
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
	if (req.method() != http::verb::connect &&
		req.method() != http::verb::delete_ &&
		req.method() != http::verb::get &&
		req.method() != http::verb::head &&
		req.method() != http::verb::options &&
		req.method() != http::verb::post &&
		req.method() != http::verb::put &&
		req.method() != http::verb::trace)
		return send(bad_request("Unknown HTTP-method"));

	// Google Chrome browser user_agent:
	const std::string chrome_value_user_agent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.100 Safari/537.36";
	// Microsoft Edge browser user_agent:
	const std::string edge_value_user_agent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.102 Safari/537.36 Edge/18.18362";

	// turn the request message into a string
	auto buff = beast::flat_buffer();
	write_message_to_string(req, buff);
	std::string req_message = beast::buffers_to_string(buff.data());

	// Respond to a CONNECT request
	if (req.method() == http::verb::connect) {
		std::cout << "-> CONNECT message received\n";
		std::cout << req_message;
		// not implemented yet
	}

	// Respond to a DELETE request
	if (req.method() == http::verb::delete_) {
		std::cout << "-> DELETE message received\n";
		std::cout << req_message;
		// not implemented yet
	}

	// Respond to a GET/HEAD request
	if (req.method() == http::verb::get ||
		req.method() == http::verb::head) {
		if (req.method() == http::verb::get)
			std::cout << "-> GET message received\n";
		if (req.method() == http::verb::head)
			std::cout << "-> HEAD message received\n";
		std::cout << req_message;
		// a GET/HEAD request can mean three things
		// 1) a download request from an app. for a file from the user space
		// 2) a request from a browser for a that renders its layout
		// 3) a download request from a browser for a file from the user space
		std::string file_name_on_server = "";
		std::string path = "";
		std::string user_agent =
			static_cast<std::string>(req[http::field::user_agent]);
		if (user_agent == "Boost.Beast/248")
		{
			// its a request from an app.
			file_name_on_server = std::string("/user_space") +
				static_cast<std::string>(req.target());
		}
		//if (user_agent != "Boost.Beast/248")
		if (user_agent == chrome_value_user_agent ||
			user_agent == edge_value_user_agent)
		{
			// assume its a request from a browser
			std::string target = static_cast<std::string>(req.target());
			if (target == "/download-and-upload.html" ||
				target == "/favicon.ico" ||
				target == "/frame-bottom.html" ||
				target == "/frame-center.html" ||
				target == "/frame-center-bottom.html" ||
				target == "/frame-center-top.html" ||
				target == "/frame-top.html" ||
				target == "/frame-top-left.html" ||
				target == "/frame-top-right.html" ||
				target == "/index.html" ||
				target == "/mk_logo_09-08-2019.png" ||
				target == "/more.html" ||
				target == "/popup-login.html" ||
				target == "/popup-register.html" ||
				target == "/popup-reset_password.html")
			{
				// it's one off the browser layout files
				file_name_on_server = std::string("/server_space") +
					static_cast<std::string>(req.target());
			}
			else
			{
				// its a download request for a file from the user space
				file_name_on_server = std::string("/user_space") +
					static_cast<std::string>(req.target());
			}
		}
		path = path_cat(doc_root, file_name_on_server);
		// Request path must be absolute and not contain "..".
		if (req.target().empty() ||
			req.target()[0] != '/' ||
			req.target().find("..") != beast::string_view::npos)
			return send(bad_request("Illegal request-target"));
		if (req.target().back() == '/')
			path.append("index.html");
		std::cout << "-> path: " << path << std::endl;
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
		// if its a GET request send a response with a payload
		if (req.method() == http::verb::get)
		{
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
		// if its a HEAD request send a response without a payload
		if (req.method() == http::verb::head)
		{
			http::response<http::empty_body> res{ http::status::ok, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, mime_type(path));
			res.content_length(size);
			res.keep_alive(req.keep_alive());
			return send(std::move(res));
		}
	}

	// Respond to an OPTIONS request
	if (req.method() == http::verb::options) {
		std::cout << "-> OPTIONS message received\n";
		std::cout << req_message;
		// not implemented yet
	}

	// Respond to a POST request
	if (req.method() == http::verb::post) {
		// a POST request can mean two things
		// 1) an access request from an app. or browser
		// 2) a file upload from a browser into the user space
		std::cout << "-> POST message received\n";
		std::cout << req_message;
		std::string user_agent =
			static_cast<std::string>(req[http::field::user_agent]);
		std::string target =
			static_cast<std::string>(req.target());
		// check if POST message is concerning a login
		if (target == "/login" ||
			target == "/register" ||
			target == "/register_confirm" ||
			target == "/reset_password_confirm"
			)
		{
			std::string response_payload = "";
			std::string user_email_address = "";
			std::string user_password = "";
			std::string user_code = "";
			filter_email_password_code(
				req,
				user_email_address,
				user_password,
				user_code,
				user_agent);
			response_payload = target + ": ";
			// remove forward slash
			response_payload.erase(0, 1);
			if (target == "/login")
			{
				HandlerForLogin handlerForlogin;
				handlerForlogin.handle_login(
					user_email_address,
					user_password,
					pSqlite,
					response_payload);
			}
			if (target == "/register")
			{
				pHandlerForRegister->handle_register(
					user_email_address,
					user_password,
					pSqlite,
					response_payload);
			}
			if (target == "/register_confirm")
			{
				pHandlerForRegister->handle_register_confirm(
					user_email_address,
					user_password,
					user_code,
					pSqlite,
					response_payload);
			}
			if (target == "/reset_password")
			{
				pHandlerForResetPassword->handle_reset_password(
					user_email_address,
					user_password,
					pSqlite,
					response_payload);
			}
			if (target == "/reset_password_confirm")
			{
				pHandlerForResetPassword->handle_reset_password_confirm(
					user_email_address,
					user_password,
					user_code,
					pSqlite,
					response_payload);
			}
			// prepare a response message
			http::response<http::string_body> res{ http::status::ok, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, "text/html");
			res.keep_alive(req.keep_alive());
			res.content_length(response_payload.length());
			res.body() = response_payload;
			res.prepare_payload();
			return send(std::move(res));
		}
		//if (user_agent != "Boost.Beast/248")
		if (user_agent == chrome_value_user_agent ||
			user_agent == edge_value_user_agent)
		{
			// assume its a request from a browser
			std::string file_name = "";
			std::string payload = "";
			filter_filename_payload_from_form_submit(
				static_cast<std::string>(req.body()),
				file_name,
				payload
			);
			save_to_disk(file_name, payload);
			// prepare a response message
			http::response<http::string_body> res{
				// no_content = 204, this is necessary to stop the
				// frame-center.html from disappearing in the browser
				http::status::no_content, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.keep_alive(req.keep_alive());
			return send(std::move(res));
		}
	}

	// Respond to a PUT request
	if (req.method() == http::verb::put) {
		std::cout << "-> PUT message received\n";
		std::cout << req_message;
		// remove all the \r-characters (return) from the req.body()
		boost::erase_all(req.body(), "\r");
		std::string file_name = static_cast<std::string>(req.target());
		std::string request_payload = req.body();
		save_to_disk(file_name, request_payload);
		// prepare a response message
		http::response<http::string_body> res{
			http::status::ok, req.version() };
		res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
		res.keep_alive(req.keep_alive());
		return send(std::move(res));
	}

	// Respond to a TRACE request
	if (req.method() == http::verb::trace) {
		std::cout << "-> TRACE message received\n";
		std::cout << req_message;
		// place the request message, along a non-standard
		// message, into the payload of the response message
		http::string_body::value_type body;
		body = std::string("server is alive\n") + req_message;
		// prepare a response message
		http::response<http::string_body> res{ http::status::ok, req.version() };
		res.set(http::field::date, beast::string_view(date_for_http_response()));
		res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
		res.set(http::field::content_type, beast::string_view("message/http"));
		res.keep_alive(false);
		res.content_length(body.size());
		res.body() = std::move(body);
		res.prepare_payload();
		// send the response message
		return send(std::move(res));
	}
}

//****************************************************************************
//*                     fail
//****************************************************************************
// Report a failure
inline void
fail(beast::error_code ec, char const* what)
{
	std::cerr << what << ": " << ec.message() << "\n";
}

//****************************************************************************
//*                     session
//****************************************************************************
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

	beast::tcp_stream stream_;
	beast::flat_buffer buffer_;
	std::shared_ptr<std::string const> doc_root_;
	std::shared_ptr<Connect2SQLite> pSqlite_;
	std::shared_ptr<HandlerForRegister> pHandlerForRegister_;
	std::shared_ptr<HandlerForResetPassword> pHandlerForResetPassword_;
	http::request<http::string_body> req_;
	std::shared_ptr<void> res_;
	send_lambda lambda_;

public:
	// Take ownership of the stream
	session(tcp::socket&& socket
		, std::shared_ptr<std::string const> const& doc_root
		, std::shared_ptr<Connect2SQLite> const& pSqlite
		, std::shared_ptr<HandlerForRegister> const& pHandlerForRegister
		, std::shared_ptr<HandlerForResetPassword> const& pHandlerForResetPassword
	)
		: stream_(std::move(socket))
		, doc_root_(doc_root)
		, pSqlite_(pSqlite)
		, pHandlerForRegister_(pHandlerForRegister)
		, pHandlerForResetPassword_(pHandlerForResetPassword)
		, lambda_(*this)
	{
		std::cout << "<<constructor>> session()\n";
	}

	// Start the asynchronous operation
	void
		run()
	{
		do_read();
	}

	void
		do_read()
	{
		// Make the request empty before reading,
		// otherwise the operation behavior is undefined.
		req_ = {};

		// Set the timeout.
		stream_.expires_after(std::chrono::seconds(SECONDS_BEFORE_EXPIRING));

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
			, pHandlerForResetPassword_
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
		// Send a TCP shutdown
		beast::error_code ec;
		stream_.socket().shutdown(tcp::socket::shutdown_send, ec);

		// At this point the connection is closed gracefully
	}
};

//****************************************************************************
//*                     listener
//****************************************************************************
// Accepts incoming connections and launches the sessions
class listener : public std::enable_shared_from_this<listener>
{
	net::io_context& ioc_;
	tcp::acceptor acceptor_;
	std::shared_ptr<std::string const> doc_root_;
	std::shared_ptr<Connect2SQLite> pSqlite_;
	std::shared_ptr<HandlerForRegister> pHandlerForRegister_;
	std::shared_ptr<HandlerForResetPassword> pHandlerForResetPassword_;

public:
	listener(
		net::io_context& ioc,
		tcp::endpoint endpoint,
		std::shared_ptr<std::string const> const& doc_root,
		std::shared_ptr<Connect2SQLite> const& pSqlite
	)
		: ioc_(ioc)
		, acceptor_(net::make_strand(ioc))
		, doc_root_(doc_root)
		, pSqlite_(pSqlite)
	{
		std::cout << "<<constructor>> listener()\n";
		HandlerForRegister handlerForRegister;
		pHandlerForRegister_ =
			std::make_shared<HandlerForRegister>(handlerForRegister);
		HandlerForResetPassword handlerForResetPassword;
		pHandlerForResetPassword_ =
			std::make_shared<HandlerForResetPassword>(handlerForResetPassword);

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
		std::cout << "remote endpoint " << remote_endpoint.c_str() << std::endl;

		if (ec)
		{
			fail(ec, "accept");
		}
		else
		{
			// Create the session and run it
			std::make_shared<session>(std::move(socket)
				, doc_root_
				, pSqlite_
				, pHandlerForRegister_
				, pHandlerForResetPassword_
				)->run();
		}

		// Accept another connection
		do_accept();
	}
};

//****************************************************************************
//*                     http_server_async
//****************************************************************************
inline int http_server_async(int argc, char* argv[])
{
	// Check command line arguments.
	if (argc != 5)
	{
		std::cerr <<
			"Usage: http-server-async <address> <port> <doc_root> <threads>\n" <<
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

	// Create and launch a listening port
	std::make_shared<listener>(
		ioc,
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