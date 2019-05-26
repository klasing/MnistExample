// Example 5.6
// Algorithms to replace characters in a string
#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;
using namespace std;
namespace ns_example_5_6 {
	inline void example_5_6() {
		string s = "Boost C++ Libraries";
		cout << "-> " << replace_first_copy(s, "+", "-") << '\n';
		cout << "-> " << replace_nth_copy(s, "+", 0, "-") << '\n';
		cout << "-> " << replace_last_copy(s, "+", "-") << '\n';
		cout << "-> " << replace_all_copy(s, "+", "-") << '\n';
		cout << "-> " << replace_head_copy(s, 5, "BOOST") << '\n';
		cout << "-> " << replace_tail_copy(s, 9, "LIBRARIES") << '\n';
	}
}