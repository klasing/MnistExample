// Listing 5.11
// Reading values from a queue with atomic operations
#include <atomic>
#include <thread>
#include <vector>

using namespace std;
namespace ns_listing_5_11 {
	extern vector<int> queue_data;
	extern atomic<int> count;
	inline void populate_queue() {
		unsigned const number_of_items = 20;
		queue_data.clear();
		for (unsigned i = 0; i < number_of_items; ++i)
			queue_data.push_back(i);
		// The initial store (1)
		count.store(number_of_items, memory_order_release);
	}
	inline void wait_for_more_items() {}
	inline void process(int i) {}
	inline void consume_queue_items() {
		while (true) {
			int item_index;
			// An RMW operation (2)
			if ((item_index = count.fetch_sub(1, memory_order_acquire)) <= 0) {
				// Wait for more items (3)
				wait_for_more_items();
				continue;
			}
			// Reading queue_data is safe (4)
			process(queue_data[item_index - 1]);
		}
	}
	inline void listing_5_11() {
		thread a(populate_queue);
		thread b(consume_queue_items);
		thread c(consume_queue_items);
		a.join();
		b.join();
		c.join();
	}
}