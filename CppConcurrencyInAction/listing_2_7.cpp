// Listing 2.7
// 
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
namespace ns_listing_2_7 {
	inline void do_work(unsigned id) {
		cout << "-> [listing 2.7] do work: " << id << endl;
	}

	inline void f() {
		vector<thread> threads;
		for (unsigned i = 0; i < 20; ++i)
			threads.push_back(thread(do_work, i));
		for_each(threads.begin(), threads.end(),
			mem_fn(&thread::join));
	}
}