#include "pch.h"

//#include "SubParagraph_8_5_1.cpp"
//#include "SubParagraph_8_5_2.cpp"

inline void paragraph_8_5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Multiple Inheritance" << endl;
		cout << "====================" << endl;
		cout << " 1) Inheriting from Multiple Classes" << endl;
		cout << " 2) Naming Collisions and Ambiguous Base Classes" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_8_5_1();
			break;
		case 2:
			//subParagraph_8_5_2();
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
