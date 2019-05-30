// Listing 5.4
// Sequential consistency implies a total ordering
#include <atomic>
#include <thread>
#include <assert.h>

using namespace std;
namespace ns_listing_5_4 {
	extern atomic<bool> x, y;
	extern atomic<int> z;

	inline void write_x() {
		x.store(true, memory_order_seq_cst); // (1)
	}
	inline void write_y() {
		y.store(true, memory_order_seq_cst); // (2)
	}
	inline void read_x_then_y() {
		while (!x.load(memory_order_seq_cst)); // (3)
		if (y.load(memory_order_seq_cst))
			++z;
	}
	inline void read_y_then_x() {
		while (!y.load(memory_order_seq_cst)); // (4)
		if (x.load(memory_order_seq_cst))
			++z;
	}

	inline int listing_5_4() {
		x = false;
		y = false;
		thread a(write_x);
		thread b(write_y);
		thread c(read_x_then_y);
		thread d(read_y_then_x);
		a.join();
		b.join();
		c.join();
		d.join();
		assert(z.load() != 0); // (5)

		return 0;
	}
}