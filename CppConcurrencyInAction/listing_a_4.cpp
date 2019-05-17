// Listing A.4
// A simple lambda with a deduced return type
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;
namespace ns_listing_A_4 {
	extern condition_variable cond;
	extern bool data_ready;
	extern mutex m;

	inline void wait_for_data() {
		unique_lock<mutex> lk(m);
		//cond.wait(lk, [] { return data_ready; });
		cond.wait(lk, []() ->bool {
			if (data_ready) {
				cout << "Data ready" << endl;
				return true;
			}
			else {
				cout << "Data not ready, resuming wait" << endl;
				return false;
			}
		});
	}

}