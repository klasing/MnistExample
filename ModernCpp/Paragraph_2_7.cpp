#include "pch.h"

#include "SubParagraph_2_7_1.cpp"
#include "SubParagraph_2_7_2.cpp"

inline void paragraph_2_7() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Designing a Chess Program" << endl;
		cout << "=========================" << endl;
		cout << " 1) Requirements" << endl;
		cout << " 2) Design Steps" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_2_7_1();
			break;
		case 2:
			subParagraph_2_7_2();
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
