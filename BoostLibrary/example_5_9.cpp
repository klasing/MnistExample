// Example 5.9
// Creating predicates with boost::algorithm::is_any_of()
#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;
using namespace std;
namespace ns_example_5_9 {
	inline void example_5_9() {
		string s = "123456789Boost C++ Libraries123456789";
		cout << "-> " << trim_left_copy_if(s, is_digit()) << '\n';
		cout << "-> " << trim_right_copy_if(s, is_digit()) << '\n';
		cout << "-> " << trim_copy_if(s, is_digit()) << '\n';
	}
}