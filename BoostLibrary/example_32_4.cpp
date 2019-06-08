// Example 32.4
// One thread for each of the two I/O service objects to execute handlers concurrently
#define _WIN32_WINNT 0x0601

#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <thread>
#include <chrono>
#include <iostream>

using namespace boost::asio;
using namespace std;
namespace ns_example_32_4 {
	inline void example_32_4() {
		io_service ioservice1;
		io_service ioservice2;

		steady_timer timer1{ ioservice1, std::chrono::seconds{3} };
		timer1.async_wait([](const boost::system::error_code& ec) {
			cout << "-> 3 sec\n";
		});

		steady_timer timer2{ ioservice2, std::chrono::seconds{3} };
		timer2.async_wait([](const boost::system::error_code& ec) {
			cout << "-> 3 sec\n";
		});

		thread thread1{ [&ioservice1]() { ioservice1.run(); } };
		thread thread2{ [&ioservice2]() { ioservice2.run(); } };
		thread1.join();
		thread2.join();
	}
}