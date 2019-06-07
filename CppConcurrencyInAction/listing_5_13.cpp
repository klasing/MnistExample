// Listing 5.13
// Enforcing ordering on nonatomic operations
#include <atomic>
#include <thread>
#include <assert.h>

using namespace std;
namespace ns_listing_5_13 {
	// x is now a plain nonatomic variable
	extern bool x;
	extern atomic<bool> y;
	extern atomic<int> z;
	inline void write_x_then_y() {
		// Store to x before the fence (1)
		x = true;
		atomic_thread_fence(memory_order_release);
		// Store to y after the fence (2)
		y.store(memory_order_relaxed);
	}
	inline void read_y_then_x() {
		// Wait until you see the write from #2 (3)
		while (!y.load(memory_order_relaxed)) {}
		atomic_thread_fence(memory_order_acquire);
		// This will read the value written by #1 (4)
		if (x)
			++z;
	}
	inline void listing_5_13() {
		x = false;
		y = false;
		thread a(write_x_then_y);
		thread b(read_y_then_x);
		a.join();
		b.join();
		// This assert won't fire // (5)
		assert(z.load() != 0);
	}
}