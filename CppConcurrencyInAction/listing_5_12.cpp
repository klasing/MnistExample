// Listing 5.12
// Relaxed operations can be ordered with fences
#include <atomic>
#include <thread>
#include <assert.h>

using namespace std;
namespace ns_listing_5_12 {
	extern atomic<bool> x, y;
	extern atomic<int> z;
	inline void write_x_then_y() {
		x.store(true, memory_order_relaxed); // (1)
		atomic_thread_fence(memory_order_release); // (2)
		y.store(true, memory_order_relaxed); // (3)
	}
	inline void read_y_then_x() {
		while (true) { // (4)
			atomic_thread_fence(memory_order_acquire); // (5)
			if (x.load(memory_order_relaxed)) // (6)
				++z;
		}
	}
	inline void listing_5_12() {
		x = false;
		y = false;
		thread a(write_x_then_y);
		thread b(read_y_then_x);
		a.join();
		b.join();
		assert(z.load() != 0); // (7)
	}
}