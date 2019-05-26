// Example 7.2
// Numbered placeholders with boost::format
#include <boost/format.hpp>
#include <iostream>

using namespace std;
namespace ns_example_7_2 {
	inline void example_7_2() {
		cout << boost::format{ "%2%/%1%/%3%" } % 12 % 5 % 2014 << '\n';
	}
}