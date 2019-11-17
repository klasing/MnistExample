// Example 32.5
// A web client with boost::asio::ip::tcp::socket
//#define _WIN32_WINNT 0x0601
//
//#include <boost/asio/io_service.hpp>
//#include <boost/asio/write.hpp>
//#include <boost/asio/buffer.hpp>
//#include <boost/asio/ip/tcp.hpp>
//#include <array>
//#include <string>
//#include <iostream>
//
//using namespace boost::asio;
//using namespace boost::asio::ip;
//using namespace std;
//namespace ns_example_32_5 {
//	extern io_service ioservice;
//	extern tcp::resolver resolv;
//	extern tcp::socket tcp_socket;
//	extern array<char, 4096> bytes;
//
//	inline void read_handler(const boost::system::error_code& ec,
//		size_t bytes_transferred) {
//		if (!ec) {
//			cout.write(bytes.data(), bytes_transferred);
//			tcp_socket.async_read_some(buffer(bytes), read_handler);
//		}
//	}
//
//	inline void connect_handler(const boost::system::error_code& ec) {
//		if (!ec) {
//			string r = "GET / HTTP/1.1\r\nHost: theboostlibraries.com\r\n\r\n";
//			write(tcp_socket, buffer(r));
//			tcp_socket.async_read_some(buffer(bytes), read_handler);
//		}
//	}
//
//	inline void resolve_handler(const boost::system::error_code& ec,
//		tcp::resolver::iterator it) {
//		if (!ec)
//			tcp_socket.async_connect(*it, connect_handler);
//	}
//
//	inline void example_32_5() {
//		tcp::resolver::query q{ "theboostcpplibraries.com", "80" };
//		resolv.async_resolve(q, resolve_handler);
//		ioservice.run();
//	}
//}
