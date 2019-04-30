#include "pch.h"

#include "SubParagraph_5_4_1.cpp"
#include "SubParagraph_5_4_2.cpp"

inline void paragraph_5_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Naming" << endl;
		cout << "======" << endl;
		cout << " 1) Choosing a Good Name" << endl;
		cout << " 2) Naming Conventions" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_5_4_1();
			break;
		case 2:
			subParagraph_5_4_2();
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
