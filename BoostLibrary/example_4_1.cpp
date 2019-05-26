// Example 4.1
// Using boost::simple_segragated_storage
#include <boost/pool/simple_segregated_storage.hpp>
#include <vector>
#include <cstddef>

using namespace std;
namespace ns_example_4_1 {
	inline void example_4_1() {
		boost::simple_segregated_storage<size_t> storage;
		vector<char> v(1024);
		storage.add_block(&v.front(), v.size(), 256);

		int* i = static_cast<int*>(storage.malloc());
		*i = 1;

		int* j = static_cast<int*>(storage.malloc_n(1, 512));
		j[10] = 2;

		storage.free(i);
		storage.free_n(j, 1, 512);

	}
}