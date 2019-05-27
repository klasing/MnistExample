// Example 8.8
// Linking a locale to a regular expression
#define BOOST_REGEX_USE_CPP_LOCALE
#include <regex>
#include <locale>
#include <string>
#include <iostream>

using namespace std;
namespace ns_example_8_8 {
	inline void example_8_8() {
		string s = "Boost k\xfct\xfcphaneleri";
		// cpp_regex_traits is not a template
		//basic_regex<char, cpp_regex_traits<char>> expr;
		//expr.imbue(locale{ "Turkish" });
		//expr = "\\w+\\s\\w+";
		//cout << "-> " << boolalpha << regex_match(s, expr) << '\n';
	}
}