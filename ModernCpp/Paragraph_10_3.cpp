#include "pch.h"

#include "SubParagraph_10_3_1.cpp"
#include "SubParagraph_10_3_2.cpp"
#include "SubParagraph_10_3_3.cpp"
#include "SubParagraph_10_3_4.cpp"

inline void paragraph_10_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Exceptions and Polymorphism" << endl;
		cout << "===========================" << endl;
		cout << " 1) The Standard Exception Hierarchy" << endl;
		cout << " 2) Catching Exceptions in a Class Hierarchy" << endl;
		cout << " 3) Writing Your Own Exception Classes" << endl;
		cout << " 4) Nested Exceptions" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_10_3_1();
			break;
		case 2:
			subParagraph_10_3_2();
			break;
		case 3:
			subParagraph_10_3_3();
			break;
		case 4:
			subParagraph_10_3_4();
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
