// taken from:
// https://en.cppreference.com/w/cpp/thread/yield
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
namespace ns_d_7_2_b {
	inline void example_d_7_2_b(chrono::microseconds us) {
		auto start = chrono::high_resolution_clock::now();
		auto end = start + us;
		do {
			this_thread::yield();
		} while (chrono::high_resolution_clock::now() < end);
	}
}