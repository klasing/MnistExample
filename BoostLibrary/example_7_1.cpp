// Example 7.1
// Formatted output with boost::format
#include <boost/format.hpp>
#include <iostream>

using namespace std;
namespace ns_example_7_1 {
	inline void example_7_1() {
		cout << boost::format{ "%1%.%2%.%3%" } % 12 % 5 % 2014 << '\n';
	}
}