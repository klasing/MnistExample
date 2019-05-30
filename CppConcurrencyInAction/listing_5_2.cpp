// Listing 5.2
// Reading and writing variables from different threads
#include <vector>
#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
namespace ns_listing_5_2 {
	extern vector<int> data;
	extern atomic<bool> data_ready(false);

	inline void reader_thread() {
		while (!data_ready.load()) { // (1)
			//this_thread::sleep(chrono::milliseconds(1));
			this_thread::sleep_for(chrono::milliseconds(1));
		}
		cout << "-> The answer=" << data[0] << '\n'; // (2)
	}
	inline void writer_thread() {
		data.push_back(42); // (3)
		data_ready = true; // (4)
	}
}