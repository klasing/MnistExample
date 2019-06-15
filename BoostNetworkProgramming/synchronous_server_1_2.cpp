// synchronous_server_1_2.cpp
#define _WIN32_WINNT 0x0601

#include <boost/shared_ptr.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/write.hpp>
#include <boost/thread.hpp>

using namespace boost::asio;
namespace ns_synchronous_server_1_2 {
	typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;

	inline void client_session(socket_ptr sock) {
		while (true) {
			char data[512];
			size_t len = sock->read_some(buffer(data));
			if (len > 0)
				write(*sock, buffer("ok", 2));
		}
	}
	inline void synchronous_server_1_2() {
		io_service service;
		ip::tcp::endpoint ep(ip::tcp::v4(), 2001);
		ip::tcp::acceptor acc(service, ep);

		while (true) {
			socket_ptr sock(new ip::tcp::socket(service));
			acc.accept(*sock);
			boost::thread(boost::bind(client_session, sock));
		}

	}
}