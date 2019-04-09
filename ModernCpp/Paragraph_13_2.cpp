#include "pch.h"

#include "SubParagraph_13_2_1.cpp"
#include "SubParagraph_13_2_2.cpp"
#include "SubParagraph_13_2_3.cpp"
#include "SubParagraph_13_2_4.cpp"
#include "SubParagraph_13_2_5.cpp"

inline void paragraph_13_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Lambda Expressions" << endl;
		cout << "==================" << endl;
		cout << " 1) Syntax" << endl;
		cout << " 2) Capture Block" << endl;
		cout << " 3) Lambda Expressions as Return Type" << endl;
		cout << " 4) Lambda Expressions as Parameters" << endl;
		cout << " 5) Examples" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_13_2_1();
			break;
		case 2:
			subParagraph_13_2_2();
			break;
		case 3:
			subParagraph_13_2_3();
			break;
		case 4:
			subParagraph_13_2_4();
			break;
		case 5:
			subParagraph_13_2_5();
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
