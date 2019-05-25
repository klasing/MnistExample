// Example 3.1
// Using BOOST_SCOPE_EXIT
#include <boost/scope_exit.hpp>
#include <iostream>

using namespace std;
namespace ns_example_3_1 {
	inline int* foo() {
		int* i = new int{ 10 };
		BOOST_SCOPE_EXIT(&i) {
			delete i;
			i = 0;
		} BOOST_SCOPE_EXIT_END
			cout << "-> " << *i << '\n';
		return i;

	}
	inline void example_3_1() {
		int* j = foo();
		cout << "-> " << j << '\n';
	}
}