#include "pch.h"

#include "SubParagraph_11_1_1.cpp"
#include "SubParagraph_11_1_2.cpp"

inline void paragraph_11_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Coding Principles" << endl;
		cout << "=================" << endl;
		cout << " 1) Use of Templates" << endl;
		cout << " 2) Use of Operator Overloading" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_11_1_1();
			break;
		case 2:
			subParagraph_11_1_2();
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
