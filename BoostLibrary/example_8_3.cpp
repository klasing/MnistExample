// Example 8.3
// Replacing characters in strings with boost::regex_replace()
#include <regex>
#include <string>
#include <iostream>

using namespace std;
namespace ns_example_8_3 {
	inline void example_8_3() {
		string s = " Boost Libraries ";
		regex expr{ "\\s" };
		string fmt{ "_" };
		cout << "-> " << regex_replace(s, expr, fmt) << '\n';
	}
}