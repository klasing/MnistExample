#include "pch.h"

//#include "SubParagraph_20_3_1.cpp"

inline void paragraph_20_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Emulating Function Partial Specialization with Overloading" << endl;
		cout << "==========================================================" << endl;
		cout << " 1) More on Deduction" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_20_3_1();
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
