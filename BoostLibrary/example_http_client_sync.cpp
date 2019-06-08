// Example http client sync
// taken from:
// https://www.boost.org/doc/libs/1_66_0/libs/beast/doc/html/beast/quick_start.html
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

// from <boost/asio/ip/tcp.hpp>
using tcp = boost::asio::ip::tcp;
// from <boost/beast/http.hpp>
namespace http = boost::beast::http;
using namespace std;
namespace ns_example_http_client_sync {
	// Performs an HTTP GET and prints the response
	inline int example_http_client_sync(int argc, char** argv) {
		try {
			// Check command line arguments,
			// i.d. the function params
			if (argc != 4 && argc != 5) {
				cerr <<
					"-> "
					"Usage: http-client-sync <host> <port> <target> [<HTTP version: 1.0 or 1.1(default)>]\n" <<
					"Example:\n" <<
					"  http-client-sync www.example.com 80 /\n" <<
					"  http-client-sync www.example.com 80 / 1.0\n";
				return EXIT_FAILURE;
			}
			auto const host = argv[1];
			auto const port = argv[2];
			auto const target = argv[3];
			int version = argc == 5 && !strcmp("1.0", argv[4]) ? 10 : 11;

			// The io_context is required for all I/O
			boost::asio::io_context ioc;

			// These objects perform our I/O
			tcp::resolver resolver(ioc);
			tcp::socket socket(ioc);

			// Look up the domain name
			auto const results = resolver.resolve(host, port);

			// Make the connection on the IP address we get from a lookup
			boost::asio::connect(socket, results.begin(), results.end());

			// Set up an HTTP GET request message
			http::request<http::string_body> req{ http::verb::get, target, version };
			req.set(http::field::host, host);
			req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

			// Send the HTTTP request to the remote host
			http::write(socket, req);

			// This buffer is used for reading and must be persisted
			boost::beast::flat_buffer buffer;

			// Declare a container to hold the response
			http::response<http::dynamic_body> res;

			// Receive the HTTP response
			http::read(socket, buffer, res);

			// Write the message to standard out
			cout << res << endl;

			// Gracefully close the socket
			boost::system::error_code ec;
			socket.shutdown(tcp::socket::shutdown_both, ec);

			// not_connected happens sometimes
			// so don't bother reporting it
			//
			if (ec && ec != boost::system::errc::not_connected)
				throw boost::system::system_error{ ec };

			// If we get here then the conniection is closed gracefully
		}
		catch (exception const& e) {
			cerr << "-> Error: " << e.what() << endl;
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}
}