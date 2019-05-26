// Example 4.3
// Changillng the segment size with boost::object_pool
#include <boost/pool/object_pool.hpp>
#include <iostream>

using namespace std;
namespace ns_example_4_3 {
	inline void example_4_3() {
		boost::object_pool<int> pool{ 32, 0 };
		pool.construct();
		cout << pool.get_next_size() << '\n';
		pool.set_next_size(8);
	}
}