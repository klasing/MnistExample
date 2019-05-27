// Example 8.5
// Flags for formats
#include <regex>
#include <string>
#include <iostream>

using namespace std;
namespace ns_example_8_5 {
	inline void example_8_5() {
		string s = "Boost Libraries";
		regex expr{ "(\\w+)\\s(\\w+)" };
		string fmt{ "\\2 \\1" };
		//cout << "-> " << regex_replace(s, expr, fmt,
		//	regex_constants::format_literal) << '\n';
		// regex_constants::format_literal is not a member of
		// regex_constants
		cout << "-> " << regex_replace(s, expr, fmt) << '\n';
	}
}