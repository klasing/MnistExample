// Example 8.2
// Searching strings with boost::regex_search()
#include <regex>
#include <string>
#include <iostream>

using namespace std;
namespace ns_example_8_2 {
	inline void example_8_2() {
		string s = "Boost Libraries";
		regex expr{ "(\\w+)\\s(\\w+)" };
		smatch what;
		if (regex_search(s, what, expr)) {
			cout << "-> " << what[0] << '\n';
			cout << "-> " << what[1] << "_" << what[2] << '\n';
		}
	}
}