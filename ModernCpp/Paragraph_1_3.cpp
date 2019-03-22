#include "pch.h"

//#include "SubParagraph_1_3_1.cpp"

inline void paragraph_1_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "C++ as an Object-Oriented Language" << endl;
		cout << "==================================" << endl;
		cout << " 1) Declaring a Class" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_1_3_1();
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
