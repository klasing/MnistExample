// Example 7.9
// boost::format with user-defined type
#include <boost/format.hpp>
#include <string>
#include <iostream>

using namespace std;
namespace ns_example_7_9 {
	struct animal {
		string name;
		int legs;
	};

	inline ostream& operator<< (ostream& os, const animal& a) {
		return os << a.name << ", " << a.legs;
	}
	inline void example_7_9() {
		animal a{"cat", 4};
		cout << boost::format{ "%1%" } %  a << '\n';
	}
}