// Listing 3.11
// Thread-safe lazy initialization using a mutex
#include <mutex>

using namespace std;
namespace ns_listing_3_11 {
	struct some_resource {
		void do_something() {}
	};
	extern shared_ptr<some_resource> resource_ptr;
	extern mutex resource_mutex;

	inline void listing_3_11() {
		// All threads are serialized here
		unique_lock<mutex> lk(resource_mutex);
		if (!resource_ptr) {
			// Only the initialization needs protection
			resource_ptr.reset(new some_resource);
		}
		lk.unlock();
		resource_ptr->do_something();
	}
}
