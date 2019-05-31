// Listing 5.1
// Implementation of a spinlock mutex using std::atomic_flag
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
#include <sstream>

using namespace std;
namespace ns_listing_5_1 {
	extern stringstream stream;

	class spinlock_mutex {
		//atomic_flag flag;
		atomic_flag flag = ATOMIC_FLAG_INIT;
	public:
		//spinlock_mutex() : flag(ATOMIC_FLAG_INIT) {}
		spinlock_mutex() {}
		void lock() {
			while (flag.test_and_set(memory_order_acquire));
		}
		void unlock() {
			flag.clear(memory_order_release);
		}
	};

	extern spinlock_mutex sm;

	inline void append_number(int x) {
		sm.lock();
		stream << "-> thread #" << x << '\n';
		sm.unlock();
	}

	inline void listing_5_1() {
		vector<thread> threads;
		for (int i = 1; i <= 10; ++i)
			threads.push_back(thread(append_number, i));
		for (auto& th : threads)
			th.join();

		cout << stream.str();
	}
}