// Listing 3.1
// Protecting a list with a mutex
#include <list>
#include <mutex>
#include <algorithm>

using namespace std;
namespace ns_listing_3_1 {
	extern list<int> some_list;
	extern mutex some_mutex;

	inline void add_to_list(int new_value) {
		lock_guard<mutex> guard(some_mutex);
		some_list.push_back(new_value);
	}

	inline bool list_contains(int value_to_find) {
		lock_guard<mutex> guard(some_mutex);
		return find(some_list.begin(), some_list.end(), value_to_find)
			!= some_list.end();
	}
}