#include <iostream>

#include "paragraph_4_4_1.cpp"
#include "paragraph_4_4_2.cpp"

using namespace std;
inline void chapter_4_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "4.4 Using synchronization of operations to simplify code" << endl;
		cout << "========================================================" << endl;
		cout << " 1) Functional programming with futures" << endl;
		cout << " 2) Synchronizing operations with message passing" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_4_4_1();
			break;
		case 2:
			paragraph_4_4_2();
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
