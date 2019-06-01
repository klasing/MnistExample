// Listing 5.9
// Transitive synchronozation using aquire and release ordering
#include <atomic>
#include <assert.h>

using namespace std;
namespace ns_listing_5_9 {
	extern atomic<int> data[];
	extern atomic<bool> sync1, sync2;

	inline void thread_1() {
		data[0].store(42, memory_order_relaxed);
		data[1].store(97, memory_order_relaxed);
		data[2].store(17, memory_order_relaxed);
		data[3].store(-141, memory_order_relaxed);
		data[4].store(2003, memory_order_relaxed);
		// Set sync1 (1)
		sync1.store(true, memory_order_release);
	}
	inline void thread_2() {
		// Loop until sync1 is set (2)
		while (!sync1.load(memory_order_acquire));
		// Set sync2 (3)
		sync2.store(true, memory_order_release);
	}
	inline void thread_3() {
		// Loop until sync2 is set (4)
		while (!sync2.load(memory_order_acquire));
		assert(data[0].load(memory_order_relaxed) == 42);
		assert(data[1].load(memory_order_relaxed) == 97);
		assert(data[2].load(memory_order_relaxed) == 17);
		assert(data[3].load(memory_order_relaxed) == -141);
		assert(data[4].load(memory_order_relaxed) == 2003);
	}
	inline void listing_5_9() {

	}
}