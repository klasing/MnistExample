// Example 2.1
// Using boost::ptr_vactor
#include <boost/ptr_container/ptr_vector.hpp>
#include <iostream>

using namespace std;
namespace ns_example_2_1 {
	inline void example_2_1() {
		boost::ptr_vector<int> v;
		v.push_back(new int{ 1 });
		v.push_back(new int{ 2 });
		cout << "-> " << v.back() << '\n';
	}
}