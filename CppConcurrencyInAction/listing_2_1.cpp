// Listing 2.1 
// A function that returns while a thread still has access to local variables
#pragma once
#include <iostream>
#include <thread>

using namespace std;
namespace ns_listing_2_1 {
	struct func {
		int& i;
		func(int& i_) : i(i_) {}
		void operator() () {
			cout << "-> [listing 2.1] loop started" << endl;
			for (unsigned j = 0; j < 1000000; ++j)
				do_something(i);
			cout << "-> [listing 2.1] loop ended" << endl;
		}
		void do_something(int& i) {}
	};
	inline void oops() {
		int some_local_state = 0;
		func my_func(some_local_state);
		thread my_thread(my_func);
		my_thread.detach();
		//my_thread.join();
	}
}