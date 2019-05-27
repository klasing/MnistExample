// As the library is part of the standard library since C++11, 
// you don’t depend on Boost.Regex if your development environment supports C++11.
// You can use identically named classes and functions in the
// namespace std if you include the header file regex.

// Example 8.1
// Comparing strings with boost::regex_match()
//#include <boost/regex.hpp>
#include <regex>
#include <string>
#include <iostream>

using namespace std;
namespace ns_example_8_1 {
	inline void example_8_1() {
		string s = "Boost Libraries";
		//boost::regex expr{ "\\w+\\s\\w+" };
		//cout << boolalpha << boost::regex_match(s, expr) << '\n';
		regex expr{ "\\w+\\s\\w+" };
		cout << boolalpha << "-> " << regex_match(s, expr) << '\n';
	}
}