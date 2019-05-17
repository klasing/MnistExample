// taken from:
// https://en.cppreference.com/w/cpp/thread/thread/detach
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
namespace ns_d_7_1_d {
	inline void independentThread() {
		cout << "-> Starting concurrent thread.\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "-> Exiting concurrent thread.\n";
	}
	inline void threadCaller() {
		cout << "-> Starting thread caller.\n";
		thread t(independentThread);
		t.detach();
		this_thread::sleep_for(chrono::seconds(1));
		cout << "-> Exiting thread caller.\n";
	}
	inline void example_d_7_1_d() {
		threadCaller();
		this_thread::sleep_for(chrono::seconds(5));
	}
}