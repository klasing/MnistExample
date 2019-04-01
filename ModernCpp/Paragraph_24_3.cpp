#include "pch.h"

#include "SubParagraph_24_3_1.cpp"
#include "SubParagraph_24_3_2.cpp"

inline void paragraph_24_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Design-Level Efficiency" << endl;
		cout << "=======================" << endl;
		cout << " 1) Cache as Much as Possible" << endl;
		cout << " 2) Use Object Pools" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_24_3_1();
			break;
		case 2:
			subParagraph_24_3_2();
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
