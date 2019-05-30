// Listing 5.5
// Relaxed operations have very few ordering requirements
#include <atomic>
#include <thread>
#include <assert.h>

using namespace std;
namespace ns_listing_5_5 {
	extern atomic<bool> x, y;
	extern atomic<int> z;

	inline void write_x_then_y() {
		x.store(true, memory_order_relaxed); // (1)
		y.store(true, memory_order_relaxed); // (2)
	}
	inline void read_y_then_x() {
		while (!y.load(memory_order_relaxed)); // (3)
		if (x.load(memory_order_relaxed)) // (4)
			++z;
	}

	inline int listing_5_5() {
		x = false;
		y = false;
		z = 0;
		thread a(write_x_then_y);
		thread b(read_y_then_x);
		a.join();
		b.join();
		assert(z.load() != 0); // (5)

		return 0;
	}
}