#include <iostream>

#include "listing_3_1.cpp"

using namespace std;
inline void paragraph_3_2_1() {
	cout << "3.2.1 Using mutexes in C++" << endl;
	cout << "--------------------------" << endl;

	using namespace ns_listing_3_1;
	add_to_list(1);
	add_to_list(2);
	add_to_list(3);
	cout << (list_contains(3) ? "-> 3 is in the list" : "-> 3 is not in the list") << endl;
	cout << (list_contains(4) ? "-> 4 is in the list" : "-> 4 is not in the list") << endl;
}