// Listing 2.5
// Returning a std::thread from a function
#include <iostream>
#include <thread>

using namespace std;
namespace ns_listing_2_5 {
	inline void some_function() {
		cout << "-> [listing 2.5] some_function()" << endl;
	}
	inline void some_other_function() {
		cout << "-> [listing 2.5] some_other_function()" << endl;
	}
	inline thread f() {
		//void some_function();
		return thread(some_function);
	}
	inline thread g() {
		//void some_other_function();
		return thread(some_other_function);
	}
	//inline void some_function() {
	//	cout << "-> [listing 2.5] some_function()" << endl;
	//}
	//inline void some_other_function() {
	//	cout << "-> [listing 2.5] some_other_function()" << endl;
	//}
}