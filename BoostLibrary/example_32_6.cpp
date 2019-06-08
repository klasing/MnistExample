// Example 32_6
// A time server with boost::asio::ip::tcp::acceptor
#define _WIN32_WINNT 0x0601

#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace std;
namespace ns_example_32_6 {
	extern io_service ioservice;
	extern tcp::endpoint tcp_endpoint;
	extern tcp::acceptor tcp_acceptor;
	extern tcp::socket tcp_socket;
	extern string data;

	inline void write_handler(const boost::system::error_code& ec,
		size_t bytes_transferred) {
		if (!ec)
			tcp_socket.shutdown(tcp::socket::shutdown_send);
	}

	inline void accept_handler(const boost::system::error_code& ec) {
		if (!ec) {
			time_t now = time(nullptr);
			data = ctime(&now);
			async_write(tcp_socket, buffer(data), write_handler);
		}
	}

	inline void example_32_6() {
		tcp_acceptor.listen();
		tcp_acceptor.async_accept(tcp_socket, accept_handler);
		ioservice.run();
	}
}
