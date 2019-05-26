// Example 5.7
// Algorithms to trim strings
#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;
using namespace std;
namespace ns_example_5_7 {
	inline void example_5_7() {
		string s = "\t Boost C++ Libraries \t";
		cout << "-> " << "_" << trim_left_copy(s) << "_" << '\n';
		cout << "-> " << "_" << trim_right_copy(s) << "_" << '\n';
		cout << "-> " << "_" << trim_copy(s) << "_" << '\n';
	}
}