// Listing 5.10
// Using std::memory_order_consume to synchronized data
#include <string>
#include <atomic>
#include <thread>
#include <chrono>
#include <assert.h>

using namespace std;
namespace ns_listing_5_10 {
	class X {
	public:
		int i;
		string s;
	};
	extern atomic<X*> p;
	extern atomic<int> a;
	inline void create_x() {
		X* x = new X;
		x->i = 42;
		x->s = "hello";
		a.store(99, memory_order_relaxed); // (1)
		p.store(x, memory_order_release); // (2)
	}
	inline void use_x() {
		X* x;
		while (!(x = p.load(memory_order_consume))) // (3)
			this_thread::sleep_for(chrono::milliseconds(1));
		assert(x->i == 42); // (4)
		assert(x->s == "hello"); // (5)
		assert(a.load(memory_order_relaxed) == 99); // (6)
	}
	inline void listing_5_10() {
		thread t1(create_x);
		thread t2(use_x);
		t1.join();
		t2.join();
	}
}