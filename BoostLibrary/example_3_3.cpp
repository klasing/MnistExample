// Example 3.3
// Using Peculiarities of BOOST_SCOPE_EXIT
#include <boost/scope_exit.hpp>
#include <iostream>

using namespace std;
namespace ns_example_3_3 {
	struct x {
		int i;

		void foo() {
			i = 10;
			BOOST_SCOPE_EXIT(void) {
				cout << "-> last\n";
			} BOOST_SCOPE_EXIT_END
				BOOST_SCOPE_EXIT(this_) {
				this_->i = 20;
				cout << "-> first\n";
			} BOOST_SCOPE_EXIT_END
		}
	};

	inline void example_3_3() {
		x obj;
		obj.foo();
		cout << "-> " << obj.i << '\n';
	}
}