// Example 7.6
// Placeholders without numbers
#include <boost/format.hpp>
#include <iostream>

using namespace std;
namespace ns_example_7_6 {
	inline void example_7_6() {
		cout << boost::format{ "%|+| %|| %||" } % 1 % 2 % 1 << '\n';
	}
}