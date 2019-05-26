// Example 4.2
// Using boost::scoped_ptr
#include <boost/pool/object_pool.hpp>

using namespace std;
namespace ns_example_4_2 {
	inline void example_4_2() {
		boost::object_pool<int> pool;

		int* i = pool.malloc();
		*i = 1;

		int* j = pool.construct(2);

		pool.destroy(i);
		pool.destroy(j);
	}
}