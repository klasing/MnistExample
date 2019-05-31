#include <iostream>

#include "listing_5_4.cpp"
#include "listing_5_5.cpp"
#include "listing_5_6.cpp"
#include "listing_5_7.cpp"
#include "listing_5_8.cpp"

using namespace std;
inline void paragraph_5_3_3() {
	cout << "5.3.3 Memory ordering for atomic operations" << endl;
	cout << "-------------------------------------------" << endl;

	cout << "a) Sequentially consistent ordering" << endl;
	ns_listing_5_4::listing_5_4();
	cout << "b) Non-Sequentially consistent memory orderings" << endl;
	cout << "c) Relaxed ordering" << endl;
	ns_listing_5_5::listing_5_5();
	ns_listing_5_6::listing_5_6();
	cout << "d) Understanding relaxed ordering" << endl;
	cout << "e) Aquire-release ordering" << endl;
	ns_listing_5_7::listing_5_7();
	ns_listing_5_8::listing_5_8();
	cout << "f) Transitive synchronization with aquire-release ordering" << endl;
}