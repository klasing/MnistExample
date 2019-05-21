#include <iostream>

#include "listing_3_13.cpp"
#include "example_44_10.cpp"

using namespace std;
inline void paragraph_3_3_2() {
	cout << "3.3.2 Protecting rarely updated data structures" << endl;        
	cout << "-----------------------------------------------" << endl;

	ns_listing_3_13::listing_3_13();

	// example added in the process of solving the linker problem
	ns_example_44_10::example_44_10();
}