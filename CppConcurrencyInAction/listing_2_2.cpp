// Listing 2.2 
// Waiting for a thread to finish
#pragma once
#include <iostream>
#include <thread>

using namespace std;
namespace ns_listing_2_2 {
	struct func {
		int& i;
		func(int& i_) : i(i_) {}
		void operator() () {
			cout << "-> [listing 2.2] loop started" << endl;
			for (unsigned j = 0; j < 1000000; ++j)
				do_something(i);
			cout << "-> [listing 2.2] loop ended" << endl;
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
		//my_thread.detach();
		//my_thread.join();
		try {
			do_something_in_current_thread();
		}
		catch (...) {
			cout << "-> [listing 2.2] waiting for thread to finish after exception is thrown" << endl;
			t.join();
			throw;
		}
		t.join();
	}
}