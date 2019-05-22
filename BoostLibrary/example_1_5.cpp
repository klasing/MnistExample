// Example 1.5
// Using boost::make_shared
#include <boost/make_shared.hpp>
#include <typeinfo>
#include <iostream>

using namespace std;
namespace ns_example_1_5 {
	inline void example_1_5() {
		auto p1 = boost::make_shared<int>(1);
		cout << "-> " << typeid(p1).name() << '\n';
		auto p2 = boost::make_shared<int[]>(10);
		cout << "-> " << typeid(p2).name() << '\n';
	}
}