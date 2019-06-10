// Example 32.7
// Coroutines with Boost.Asio
#define _WIN32_WINNT 0x0601

#include <boost/asio/io_service.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <list>
#include <string>
#include <ctime>

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace std;
namespace ns_example_32_7 {
	extern io_service ioservice;
	extern tcp::endpoint tcp_endpoint;
	extern tcp::acceptor tcp_acceptor;
	extern list<tcp::socket> tcp_sockets;

	inline void do_write(tcp::socket& tcp_socket, yield_context yield) {
		time_t  now = time(nullptr);
		string data = ctime(&now);
		async_write(tcp_socket, buffer(data), yield);
		tcp_socket.shutdown(tcp::socket::shutdown_send);
	}

	inline void do_accept(yield_context yield) {
		for (int i = 0; i < 2; ++i) {
			tcp_sockets.emplace_back(ioservice);
			tcp_acceptor.async_accept(tcp_sockets.back(), yield);
			spawn(ioservice, [](yield_context yield) {
				do_write(tcp_sockets.back(), yield);
			});
		}
	}

	inline void example_32_7() {
		tcp_acceptor.listen();
		spawn(ioservice, do_accept);
		ioservice.run();
	}
}