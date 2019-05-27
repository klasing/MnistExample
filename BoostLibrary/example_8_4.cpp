// Example 8.4
// Format with references to groups in regular expressions
#include <regex>
//#include <boost/regex.hpp>
#include <string>
#include <iostream>

using namespace std;
namespace ns_example_8_4 {
	inline void example_8_4() {
		string s = "Boost Libraries";
		regex expr{ "(\\w+)\\s(\\w+)" };
		//boost::regex expr{ "(\\w+)\\s(\\w+)" };
		string fmt{ "\\2 \\1" };
		cout << "-> " << regex_replace(s, expr, fmt) << '\n';
		//cout << "-> " << boost::regex_replace(s, expr, fmt) << '\n';
	}
}