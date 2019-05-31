// Listing 5.6
// Relaxed operations on multiple threads
#include <thread>
#include <atomic>
#include <iostream>

using namespace std;
namespace ns_listing_5_6 {
	extern atomic<int> x, y, z; // (1)
	extern atomic<bool> go; // (2)

	unsigned const loop_count = 10;

	//struct read_values {
	//	int x, y, z;
	//};
	class read_values {
	public:
		int x, y, z;
	};

	//read_values values1[loop_count];
	extern read_values values1[];
	extern read_values values2[];
	extern read_values values3[];
	extern read_values values4[];
	extern read_values values5[];

	inline void increment(atomic<int>* var_to_inc, read_values* values) {
		// Spin, waiting for the signal (3)
		while (!go)
			this_thread::yield();
		for (unsigned i = 0; i < loop_count; ++i) {
			values[i].x = x.load(memory_order_relaxed);
			values[i].y = y.load(memory_order_relaxed);
			values[i].z = z.load(memory_order_relaxed);
			var_to_inc->store(i + 1, memory_order_relaxed); // (4)
			this_thread::yield();
		}
	}

	inline void read_vals(read_values* values) {
		// Spin, waiting for the signal (5)
		while (!go)
			this_thread::yield();
		for (unsigned i = 0; i < loop_count; ++i) {
			values[i].x = x.load(memory_order_relaxed);
			values[i].y = y.load(memory_order_relaxed);
			values[i].z = z.load(memory_order_relaxed);
			this_thread::yield();
		}
	}

	inline void print(read_values* v) {
		for (unsigned i = 0; i < loop_count; ++i) {
			if (i)
				cout << ",";
			cout << "(" << v[i].x << "," << v[i].y << "," << v[i].z << ")";
		}
		cout << endl;
	}

	inline void listing_5_6() {
		thread t1(increment, &x, values1);
		thread t2(increment, &y, values2);
		thread t3(increment, &z, values3);
		thread t4(read_vals, values4);
		thread t5(read_vals, values5);

		// Signal to start execution of the main loop (6)
		go = true;

		t5.join();
		t4.join();
		t3.join();
		t2.join();
		t1.join();

		// Print the final values (7)
		print(values1);
		print(values2);
		print(values3);
		print(values4);
		print(values5);
	}
}