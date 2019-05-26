// Example 5.10
// Algorithms to compare string with others
#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;
using namespace std;
namespace ns_example_5_10 {
	inline void example_5_10() {
		string s = "Boost C++ Libraries";
		cout.setf(ios::boolalpha);
		cout << "-> " << starts_with(s, "Boost") << '\n';
		cout << "-> " << ends_with(s, "Libraries") << '\n';
		cout << "-> " << contains(s, "C++") << '\n';
		cout << "-> " << lexicographical_compare(s, "Boost") << '\n';
	}
}