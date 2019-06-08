// Example 32.1
// Using boost::asio::steady_timer
#define _WIN32_WINNT 0x0601

#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <thread>
#include <chrono>
#include <iostream>

using namespace boost::asio;
using namespace std;
namespace ns_example_32_1 {
	//// non blocking
	inline void example_32_1() {
		io_service ioservice;

		steady_timer timer{ ioservice, std::chrono::seconds{5} };
		timer.async_wait([](const boost::system::error_code& ec) {
			cout << "-> 5 sec (non blocking)\n";
		});

		//ioservice.run();
		// from here, the example is slightly modified
		//thread a{ static_cast<io_context::count_type(io_service::*)()>(&io_service::run), &ioservice };
		thread a{ [&ioservice]() { ioservice.run(); } };
		a.detach();

		cout << "-> doing something else" << endl;

		steady_timer timer1{ ioservice, std::chrono::seconds{6} };
		timer1.wait();
		cout << "-> 6 sec (blocking)\n";
	}
}