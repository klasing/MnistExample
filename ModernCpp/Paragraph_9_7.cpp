#include "pch.h"

#include "SubParagraph_9_7_1.cpp"
#include "SubParagraph_9_7_2.cpp"

inline void paragraph_9_7() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "C Utilities" << endl;
		cout << "===========" << endl;
		cout << " 1) Variable-Length Argument Lists" << endl;
		cout << " 2) Preprocessor Macros" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_9_7_1();
			break;
		case 2:
			subParagraph_9_7_2();
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
