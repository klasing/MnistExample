// Taken from:
// http://www.cplusplus.com/reference/atomic/atomic_flag/
// using atomic_flag as a lock
#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <sstream>

using namespace std;
namespace ns_cppref_use_atomic_flag {
	extern atomic_flag lock_stream;
	extern stringstream stream;

	inline void append_number(int x) {
		while (lock_stream.test_and_set()) {}
		stream << "-> thread #" << x << '\n';
		lock_stream.clear();
	}

	inline void cpp_ref_use_atomic_flag() {
		vector<thread> threads;
		for (int i = 1; i < 10; ++i)
			threads.push_back(thread(append_number, i));

		for (auto& th : threads)
			th.join();

		cout << "-> " << stream.str();
	}
}