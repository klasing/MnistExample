// Example 5.3
// Algorithms to remove characters from a string
#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;
using namespace std;
namespace ns_example_5_3 {
	inline void example_5_3() {
		string s = "Boost C++ Libraries";
		cout << "-> " << erase_first_copy(s, "s") << '\n';
		cout << "-> " << erase_nth_copy(s, "s", 0) << '\n';
		cout << "-> " << erase_last_copy(s, "s") << '\n';
		cout << "-> " << erase_all_copy(s, "s") << '\n';
		cout << "-> " << erase_head_copy(s, 5) << '\n';
		cout << "-> " << erase_tail_copy(s, 9) << '\n';
	}
}