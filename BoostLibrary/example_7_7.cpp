// Example 7.7
// boost::format with the syntax used from std::printf()
#include <boost/format.hpp>
#include <iostream>

using namespace std;
namespace ns_example_7_7 {
	inline void example_7_7() {
		cout << boost::format{ "%+d %d %d" } % 1 % 2 % 1 << '\n';
	}
}