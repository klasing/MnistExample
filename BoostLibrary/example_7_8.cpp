// Example 7.8
// boost::format with seemingly invalid placeholders
#include <boost/format.hpp>
#include <iostream>

using namespace std;
namespace ns_example_7_8 {
	inline void example_7_8() {
		cout << boost::format{ "%+s %s %s" } % 1 % 2 % 1 << '\n';
	}
}