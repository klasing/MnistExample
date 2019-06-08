// Example websocket client sync
// taken from:
// https://www.boost.org/doc/libs/1_66_0/libs/beast/doc/html/beast/quick_start.html
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

// from <boost/asio/ip/tcp.hpp>
using tcp = boost::asio::ip::tcp;
// from <boost/beast/websocket.hpp>
namespace websocket = boost::beast::websocket;
using namespace std;
namespace ns_example_websocket_client_sync {
	// Sends a WebSocket message and prints the response
	inline int example_websocket_client_sync(int argc, char** argv) {
		try {
			// Check command line arguments.
			if (argc != 4) {
				cerr <<
					"-> " <<
					"Usage: websocket-client-sync <host> <port> <text>\n" <<
					"Example:\n" <<
					"  websocket-client-sync 80 \"Hello, world!\"\n";
					return EXIT_FAILURE;
			}
			auto const host = argv[1];
			auto const port = argv[2];
			auto const text = argv[3];

			// The io_context is required for all I/O
			boost::asio::io_context ioc;

			// These objects perform our I/O
			tcp::resolver resolver(ioc);
			websocket::stream<tcp::socket> ws(ioc);

			// Lookup the domain name
			auto const results = resolver.resolve(host, port);

			// Make the connection on the IP address we get from a lookup
			boost::asio::connect(ws.next_layer(), results.begin(), results.end());

			// Perform the websocket handshake
			ws.handshake(host, "/");

			// Send the message
			ws.write(boost::asio::buffer(string(text)));

			// This buffer will hold the incoming message
			boost::beast::multi_buffer buffer;

			// Read a message into our buffer
			ws.read(buffer);

			// Close the WebSocket connection
			ws.close(websocket::close_code::normal);

			// If we get here then the connection is closed gracefully

			// The buffers() function helps print a ConstBufferSequence
			//cout << boost::beast::buffers(buffer.data()) << endl;
			cout << boost::beast::buffers_to_string(buffer.data()) << endl;
		}
		catch (exception const& e) {
			cerr << "-> Error: " << e.what() << endl;
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}
}