// Example 4.6
// Using boost::pool_allocator
#define BOOST_POOL_NO_MT
#include <boost/pool/pool_alloc.hpp>
#include <list>

using namespace std;
namespace ns_example_4_6 {
	inline void example_4_6() {
		typedef boost::fast_pool_allocator<int,
			boost::default_user_allocator_new_delete,
			boost::details::pool::default_mutex,
			64, 128> allocator;

		list<int, allocator> l;
		for (int i = 0; i < 1000; ++i)
			l.push_back(i);

		l.clear();
		boost::singleton_pool<boost::fast_pool_allocator_tag, sizeof(int)>::
			purge_memory();
	}
}