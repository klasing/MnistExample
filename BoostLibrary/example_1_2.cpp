// Example 1.2
// Using boost::scoped_array
#include <boost/scoped_array.hpp>

using namespace std;
namespace ns_example_1_2 {
	inline void example_1_2() {
		boost::scoped_array<int> p{ new int[2] };
		*p.get() = 1;
		p[1] = 2;
		p.reset(new int[3]);
	}
}