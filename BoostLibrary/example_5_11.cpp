// Example 5.11
// Introduces a function that splits a string into smaller parts
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace boost::algorithm;
using namespace std;
namespace ns_example_5_11 {
	inline void example_5_11() {
		string s = "Boost C++ Libraries";
		vector<string> v;
		split(v, s, is_space());
		cout << "-> " << v.size() << '\n';
		for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it)
			cout << "-> " << *it << endl;
	}
}