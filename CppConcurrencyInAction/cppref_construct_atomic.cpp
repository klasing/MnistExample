// Taken from:
// http://www.cplusplus.com/reference/atomic/atomic/atomic/
// constructing atomics
#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;
namespace ns_cppref_construct_atomic {
	extern atomic<bool> ready;
	extern atomic_flag winner = ATOMIC_FLAG_INIT;

	inline void count1m(int id) {
		// wait for the ready signal
		while (!ready)
			this_thread::yield();
		// go! count to 1 million
		for (volatile int i = 0; i < 1000000; ++i) {}
		if (!winner.test_and_set())
			cout << "-> thread #" << id << " won!\n";
	}
	inline void cppref_construct_atomic() {
		vector<thread> threads;
		cout << "-> Spawning 10 threads that count to 1 million...\n";
		for (int i = 1; i < 10; ++i)
			threads.push_back(thread(count1m, i));
		ready = true;
		for (auto& th : threads)
			th.join();
	}
}