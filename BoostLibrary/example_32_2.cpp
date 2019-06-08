// Example 32.2
// Two asynchronous operations with boost::asio::steady_timer
#define _WIN32_WINNT 0x0601

#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <thread>
#include <chrono>
#include <iostream>

using namespace boost::asio;
using namespace std;
namespace ns_example_32_2 {
	inline void example_32_2() {
		io_service ioservice;

		steady_timer timer1{ ioservice, std::chrono::seconds{3} };
		timer1.async_wait([](const boost::system::error_code& ec) {
			cout << "-> 3 sec\n";
		});

		steady_timer timer2{ ioservice, std::chrono::seconds{4} };
		timer2.async_wait([](const boost::system::error_code& ec) {
			cout << "-> 4 sec\n";
		});

		ioservice.run();
	}
}