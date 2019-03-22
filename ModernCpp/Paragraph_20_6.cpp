#include "pch.h"

//#include "SubParagraph_20_6_1.cpp"
//#include "SubParagraph_20_6_2.cpp"

inline void paragraph_20_6() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Variadic Templates" << endl;
		cout << "==================" << endl;
		cout << " 1) Type-Safe Variable-Length Argument Lists" << endl;
		cout << " 2) Variable Number of Mix-In Classes" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_20_6_1();
			break;
		case 2:
			//subParagraph_20_6_2();
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
