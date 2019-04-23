#include "pch.h"

#include "SubParagraph_10_2_1.cpp"
#include "SubParagraph_10_2_2.cpp"
#include "SubParagraph_10_2_3.cpp"
#include "SubParagraph_10_2_4.cpp"
#include "SubParagraph_10_2_5.cpp"

inline void paragraph_10_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Exception Mechanics" << endl;
		cout << "===================" << endl;
		cout << " 1) Throwing and Catching Exceptions" << endl;
		cout << " 2) Exception Types" << endl;
		cout << " 3) Throwing and Catching Multiple Exceptions" << endl;
		cout << " 4) Uncaught Exceptions" << endl;
		cout << " 5) Throw List" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_10_2_1();
			break;
		case 2:
			subParagraph_10_2_2();
			break;
		case 3:
			subParagraph_10_2_3();
			break;
		case 4:
			subParagraph_10_2_4();
			break;
		case 5:
			subParagraph_10_2_5();
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
