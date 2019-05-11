// Listing 2.3 
// Using RAII to wait for a thread to complete
// Resource Aquisition Is Initialization (RAII)
#pragma once
#include <iostream>
#include <thread>

using namespace std;
namespace ns_listing_2_3 {
	class thread_guard {
		thread& t;
	public:
		explicit thread_guard(thread& t_) : t(t_) {}
		~thread_guard() {
			if (t.joinable())
				t.join();
		}
		thread_guard(thread_guard const&) = delete;
		thread_guard& operator= (thread_guard const&) = delete;
	};
	struct func {
		int& i;
		func(int& i_) : i(i_) {}
		void operator() () {
			cout << "-> [listing 2.3] loop started" << endl;
			for (unsigned j = 0; j < 1000000; ++j)
				do_something(i);
			cout << "-> [listing 2.3] loop ended" << endl;
		}
		void do_something(int& i) {}
	};
	inline void do_something_in_current_thread() {
		throw ("exception thrown");
	}
	inline void f() {
		int some_local_state = 0;
		func my_func(some_local_state);
		thread t(my_func);
		thread_guard g(t);

		do_something_in_current_thread();
	}
}