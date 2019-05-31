// Listing 5.7
// Aquire-release doesn't imply a total ordering
#include <atomic>
#include <thread>
#include <assert.h>

using namespace std;
namespace ns_listing_5_7 {
	extern atomic<bool> x, y;
	extern atomic<int> z;

	inline void write_x() {
		x.store(true, memory_order_release);
	}
	inline void write_y() {
		y.store(true, memory_order_release);
	}
	inline void read_x_then_y() {
		while (!x.load(memory_order_acquire));
		if (y.load(memory_order_acquire)) // (1)
			++z;
	}
	inline void read_y_then_x() {
		while (!y.load(memory_order_acquire));
		if (x.load(memory_order_acquire)) // (2)
			++z;
	}
	inline void listing_5_7() {
		x = false;
		y = false;
		z = 0;
		thread a(write_x);
		thread b(write_y);
		thread c(read_x_then_y);
		thread d(read_y_then_x);
		a.join();
		b.join();
		c.join();
		d.join();
		assert(z.load() != 0); // (3)
	}
}
