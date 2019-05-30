//// Listing 5.6
//// Relaxed operations on multiple threads
//#include <thread>
//#include <atomic>
//#include <iostream>
//
//using namespace std;
//namespace ns_listing_5_6 {
//	atomic<int> x(0), y(0), z(0);
//	atomic<bool> go(false);
//
//	extern unsigned const loop_count;
//
//	struct read_values {
//		int x, y, z;
//	};
//
//	read_values values1[loop_count];
//
//	inline void increment(atomic<int>* var_to_inc, read_values* values) {
//		while (!go)
//			this_thread::yield();
//		for (unsigned i = 0; i < loop_count; ++i) {
//			values[i].x = x.load(memory_order_relaxed);
//			values[i].y = y.load(memory_order_relaxed);
//			values[i].z = z.load(memory_order_relaxed);
//			var_to_inc->store(i + 1, memory_order_relaxed);
//			this_thread::yield();
//		}
//	}
//
//	inline void read_vals(read_values* values) {
//		while (!go)
//			this_thread::yield();
//		for (unsigned i = 0; i < loop_count; ++i) {
//			values[i].x = x.load(memory_order_relaxed);
//			values[i].y = y.load(memory_order_relaxed);
//			values[i].z = z.load(memory_order_relaxed);
//			this_thread::yield();
//		}
//	}
//
//	inline void print(read_values* v) {
//		for (unsigned i = 0; i < loop_count; ++i) {
//			if (i)
//				cout << ",";
//			cout << "(" << v[i].x << v[i].y << "," << v[i].z << ")";
//		}
//		cout << endl;
//	}
//
//	inline void listing_5_6() {
//		thread t1(increment, &x, values1);
//	}
//}