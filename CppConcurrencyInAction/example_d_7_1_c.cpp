// taken from:
// https://en.cppreference.com/w/cpp/thread/thread/join
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
namespace ns_d_7_1_c {
	inline void foo() {
		// simulate expensive operation
		this_thread::sleep_for(chrono::seconds(1));
	}
	inline void bar() {
		// simulate expensive operation
		this_thread::sleep_for(chrono::seconds(1));
	}
	inline void example_d_7_1_c() {
		cout << "-> starting first helper...\n";
		thread helper1(foo);

		cout << "=> starting second helpre...\n";
		thread helper2(bar);

		cout << "-> waiting for helpers to finish..." << endl;
		helper1.join();
		helper2.join();

		cout << "-> done!\n";
	}
}