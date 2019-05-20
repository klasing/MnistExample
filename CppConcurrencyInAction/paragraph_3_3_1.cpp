#include <iostream>

#include "listing_3_11.cpp"
#include "listing_3_12.cpp"

using namespace std;
inline void paragraph_3_3_1() {
	cout << "3.3.1 Protecting shared data during initialization" << endl;
	cout << "--------------------------------------------------" << endl;

	ns_listing_3_11::listing_3_11();
	ns_listing_3_12::listing_3_12();
}