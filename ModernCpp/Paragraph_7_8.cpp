#include "pch.h"

#include "SubParagraph_7_8_1.cpp"

inline void paragraph_7_8() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Building Stable Interfaces" << endl;
		cout << "==========================" << endl;
		cout << " 1) Using Interface and Implementation Classes" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_7_8_1();
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
