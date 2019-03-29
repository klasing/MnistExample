#include "pch.h"

#include "SubParagraph_22_2_1.cpp"
#include "SubParagraph_22_2_2.cpp"

inline void paragraph_22_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Atomic Operations Library" << endl;
		cout << "=========================" << endl;
		cout << " 1) Atomic Type Example" << endl;
		cout << " 2) Atomic Operations" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_22_2_1();
			break;
		case 2:
			subParagraph_22_2_2();
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
