// Example 4.4
// Using boost::scoped_ptr
#include <boost/pool/singleton_pool.hpp>

using namespace std;
namespace ns_example_4_4 {
	struct int_pool {};
	typedef boost::singleton_pool<int_pool, sizeof(int)> singleton_int_pool;

	inline void example_4_4() {
		int* i = static_cast<int*>(singleton_int_pool::malloc());
		*i = 1;

		int* j = static_cast<int*>(singleton_int_pool::ordered_malloc(10));
		j[9] = 2;

		singleton_int_pool::release_memory();
		singleton_int_pool::purge_memory();
	}
}