#include <iostream>

#include "paragraph_5_1_1.cpp"
#include "paragraph_5_1_2.cpp"
#include "paragraph_5_1_3.cpp"

using namespace std;
inline void chapter_5_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "5.1 Memory model basics" << endl;
		cout << "=======================" << endl;
		cout << " 1) Objects and memory locations" << endl;
		cout << " 2) Objects, memory locations, and concurrency" << endl;
		cout << " 3) Modification orders" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_5_1_1();
			break;
		case 2:
			paragraph_5_1_2();
			break;
		case 3:
			paragraph_5_1_3();
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
