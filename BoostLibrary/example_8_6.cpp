// Example 8.6
// Iterating over strings with boost::regex_token_iterator
#include <regex>
#include <string>
#include <iostream>

using namespace std;
namespace ns_example_8_6 {
	inline void example_8_6() {
		string s = "Boost Libraries";
		regex expr{ "\\w+" };
		regex_token_iterator<string::iterator> it{ s.begin(), s.end(),
			expr };
		regex_token_iterator<string::iterator> end;
		while (it != end)
			cout << "-> " << *it++ << '\n';
	}
}