// Listing 5.8
// Aquire-release operations can impose ordering on relaxed operations
#include <atomic>
#include <thread>
#include <assert.h>

using namespace std;
namespace ns_listing_5_8 {
	extern atomic<bool> x, y;
	extern atomic<int> z;

	inline void write_x_then_y() {
		// Spin, waiting for y to be set true (1)
		x.store(true, memory_order_relaxed);
		y.store(true, memory_order_release); // (2)
	}
	inline void read_y_then_x() {
		while (!y.load(memory_order_acquire)); // (3)
		if (x.load(memory_order_relaxed)) // (4)
			++z;
	}
	inline void listing_5_8() {
		x = false;
		y = false;
		z = 0;
		thread a(write_x_then_y);
		thread b(read_y_then_x);
		a.join();
		b.join();
		assert(z.load() != 0); // (5)
	}
}