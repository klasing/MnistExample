#include "pch.h"

#include "SubParagraph_13_1_1.cpp"
#include "SubParagraph_13_1_2.cpp"
#include "SubParagraph_13_1_3.cpp"

inline void paragraph_13_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Overview of Algorithms" << endl;
		cout << "======================" << endl;
		cout << " 1) The find and find_if Algorithms" << endl;
		cout << " 2) The accumulate Algorithms" << endl;
		cout << " 3) C++11 Move Semantics with Algorithms" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_13_1_1();
			break;
		case 2:
			subParagraph_13_1_2();
			break;
		case 3:
			subParagraph_13_1_3();
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
