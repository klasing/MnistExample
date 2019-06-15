// asynchronous_client_1_2.cpp
#define _WIN32_WINNT 0x0601

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/system/error_code.hpp>

using namespace boost::asio;
namespace ns_asynchronous_client_1_2{
	inline void connect_handler(const boost::system::error_code& ec) {
		// her we know we connected successfully
		// if ec indicates success
	}

	inline void asynchronous_client_1_2() {
		io_service service;
		ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);
		ip::tcp::socket sock(service);
		sock.async_connect(ep, connect_handler);
		service.run();
	}
}