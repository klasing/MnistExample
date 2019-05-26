// Example 5.8
// Creating predicates with boost::algorithm::is_any_of()
#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;
using namespace std;
namespace ns_example_5_8 {
	inline void example_5_8() {
		string s = "-- Boost C++ Libraries --";
		cout << "-> " << trim_left_copy_if(s, is_any_of("-")) << '\n';
		cout << "-> " << trim_right_copy_if(s, is_any_of("-")) << '\n';
		cout << "-> " << trim_copy_if(s, is_any_of("-")) << '\n';
	}
}