#include <iostream>

#include "listing_5_2.cpp"

#include "paragraph_5_3_1.cpp"
#include "paragraph_5_3_2.cpp"
#include "paragraph_5_3_3.cpp"
#include "paragraph_5_3_4.cpp"
#include "paragraph_5_3_5.cpp"
#include "paragraph_5_3_6.cpp"

using namespace std;
inline void chapter_5_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	ns_listing_5_2::listing_5_2();

	while (bProceed) {
		cout << "5.3 Sychronizing operations and enforcing ordering" << endl;
		cout << "==================================================" << endl;
		cout << " 1) The synchronizes-with relationship" << endl;
		cout << " 2) The happens-before relationship" << endl;
		cout << " 3) Memory ordering for atomic operations" << endl;
		cout << " 4) Release sequences and synchronizes-with" << endl;
		cout << " 5) Fences" << endl;
		cout << " 6) Ordering nonatomic operations with atomics" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_5_3_1();
			break;
		case 2:
			paragraph_5_3_2();
			break;
		case 3:
			paragraph_5_3_3();
			break;
		case 4:
			paragraph_5_3_4();
			break;
		case 5:
			paragraph_5_3_5();
			break;
		case 6:
			paragraph_5_3_6();
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			cout << "The entered number is not recognized, please try again." << endl;
		} // eof switch
	}
}
