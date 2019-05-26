// Example 5.5
// Concatenating strings with boost::algorithm::join()
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace boost::algorithm;
using namespace std;
namespace ns_example_5_5 {
	inline void example_5_5() {
		vector<string>  v{ "Boost","C++","Libraries" };
		cout << "-> " << join(v, " ") << '\n';
	}
}