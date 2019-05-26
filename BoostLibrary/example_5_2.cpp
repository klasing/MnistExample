// Example 5.2
// Converting strings to uppercase with a locale
#include <boost/algorithm/string.hpp>
#include <string>
#include <locale>
#include <iostream>

using namespace boost::algorithm;
using namespace std;
namespace ns_example_5_2 {
	inline void example_5_2() {
		string s = "Boost C++ k\xfct\xfcphaneleri";
		string upper_case1 = to_upper_copy(s);
		string upper_case2 = to_upper_copy(s, locale{ "Turkish" });
		locale::global(locale{ "Turkish" });
		cout << "-> " << upper_case1 << '\n';
		cout << "-> " << upper_case2 << '\n';
	}
}