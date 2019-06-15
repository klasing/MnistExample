// asynchronous_server_1_2.cpp
#define _WIN32_WINNT 0x0601

#include <boost/shared_ptr.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/bind/bind.hpp>
#include <boost/system/error_code.hpp>

using namespace boost::asio;
namespace ns_asynchronous_server_1_2 {
	typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;
	io_service service;
	ip::tcp::endpoint ep(ip::tcp::v4(), 2001);
	ip::tcp::acceptor acc(service, ep);

	void handle_accept(socket_ptr, const boost::system::error_code&);
	inline void start_accept(socket_ptr sock) {
		boost::system::error_code _l;

		acc.async_accept(*sock, boost::bind(handle_accept, sock, _l));
	}
	inline void handle_accept(socket_ptr sock, 
		const boost::system::error_code& err) {
		if (err) 
			return;

		// at this point you can read/write to the socket

		// keep service.run() busy
		socket_ptr sock_(new ip::tcp::socket(service));
		start_accept(sock);
	}

	inline void asynchronous_server_1_2() {
		socket_ptr sock(new ip::tcp::socket(service));
		start_accept(sock);
		service.run();
	}
}