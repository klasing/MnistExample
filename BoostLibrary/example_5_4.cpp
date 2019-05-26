// Example 5.4
// Searching for substrings with boost::algorithm::find_first()
#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;
using namespace std;
namespace ns_example_5_4 {
	inline void example_5_4() {
		string s = "Boost C++ Libraries";
		boost::iterator_range<string::iterator> r = find_first(s, "C++");
		cout << "-> " << r << '\n';
		r = find_first(s, "xyz");
		cout << "-> " << r << '\n';
	}
}