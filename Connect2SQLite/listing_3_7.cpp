// Listing 3.7
// Using a lock hierarchy to prevent deadlock
#include <mutex>

using namespace std;
namespace ns_listing_3_7 {
	//hierarchical_mutex high_level_mutex(10000);
	//hierarchical_mutex low_level_mutex(5000);

	//int do_low_level_stuff();

	//int low_level_func() {
	//	lock_guard<hierarchical_mutex> lk(low_level_mutex);
	//	return do_low_level_stuff();
	//}

	//void high_level_stuff(int some_param);

	//void high_level_func() {
	//	hierarchical_mutex low_level_mutex(5000);
	//	high_level_stuff(low_level_func());
	//}

	//void thread_a() {
	//	high_level_func();
	//}

	//hierarchical_mutex other_mutex(100);
	//void do_other_stuff();

	//void other_stuff() {
	//	high_level_func();
	//	do_other_stuff();
	//}

	//void thread_b() {
	//	hierarchical_mutex low_level_mutex(5000);
	//	other_stuff();
	//}
}