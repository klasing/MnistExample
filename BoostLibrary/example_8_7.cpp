// Example 8.7
// Accessing groups with boost::regex_token_iterator
#include <regex>
#include <string>
#include <iostream>

using namespace std;
namespace ns_example_8_7 {
	inline void example_8_7() {
		string s = "Boost Libraries";
		regex expr{ "(\\w)\\w+" };
		regex_token_iterator<string::iterator> it{ s.begin(), s.end(),
			expr, 1 };
		regex_token_iterator<string::iterator> end;
		while (it != end)
			cout << "-> " << *it++ << '\n';
	}
}