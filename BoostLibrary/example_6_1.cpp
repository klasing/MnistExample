// Example 6.1
// Using boost::lexical_cast
#include <boost/lexical_cast.hpp>
#include <string>
#include <iostream>

using namespace std;
namespace ns_example_6_1 {
	inline void example_6_1() {
		string s = boost::lexical_cast<string>(123);
		cout << "-> " << s << '\n';
		double d = boost::lexical_cast<double>(s);
		cout << "-> " << d << '\n';
	}
}