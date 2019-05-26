// Example 5.1
// Converting strings to uppercase
#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;
using namespace std;
namespace ns_example_5_1 {
	inline void example_5_1() {
		string s = "Boost C++ Libraries";
		cout << "-> " << to_upper_copy(s) << '\n';
	}
}