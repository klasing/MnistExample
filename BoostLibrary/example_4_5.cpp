// Example 4.5
// Using boost::pool_allocator
#include <boost/pool/pool_alloc.hpp>
#include <vector>

using namespace std;
namespace ns_example_4_5 {
	inline void example_4_5() {
		vector<int, boost::pool_allocator<int>> v;
		for (int i = 0; i < 1000; ++i)
			v.push_back(i);

		v.clear();
		boost::singleton_pool<boost::pool_allocator_tag, sizeof(int)>::
			purge_memory();
	}
}