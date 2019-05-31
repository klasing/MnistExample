// Example_5_1
// using atomic_flag as a lock
// taken from:
// http://www.cplusplus.com/reference/atomic/atomic_flag/
#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <sstream>

using namespace std;
namespace ns_example_5_1 {
	extern atomic_flag lock_stream;
	extern stringstream stream;

	inline void append_number(int x) {
		while (lock_stream.test_and_set()) {}
		stream << "-> thread #" << x << '\n';
		lock_stream.clear();
	}

	inline int example_5_1() {
		vector<thread> threads;
		for (int i = 1; i <= 10; ++i)
			threads.push_back(thread(append_number, i));
		for (auto& th : threads)
			th.join();

		cout << stream.str();

		return 0;
	}
}