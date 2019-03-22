#include "pch.h"

//#include "SubParagraph_18_5_1.cpp"
//#include "SubParagraph_18_5_2.cpp"

inline void paragraph_18_5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Overloading the Subscripting Operator" << endl;
		cout << "=====================================" << endl;
		cout << " 1) Providing Read-Only Access with operator[]" << endl;
		cout << " 2) Non-Integral Array Indices" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_18_5_1();
			break;
		case 2:
			//subParagraph_18_5_2();
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
