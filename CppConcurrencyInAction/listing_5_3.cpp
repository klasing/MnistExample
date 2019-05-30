// Listing 5.3
// Order of evaluation of arguments to a function call is unspecified
#include <iostream>

using namespace std;
namespace ns_listing_5_3 {
	inline void foo(int a, int b) {
		cout << a << ", " << b << endl;
	}
	inline int get_num() {
		static int i = 0;
		return ++i;
	}
	inline int listing_5_3() {
		// Calls to get_num() are unordered
		foo(get_num(), get_num());
		return 0;
	}
}