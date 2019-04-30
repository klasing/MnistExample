#include "pch.h"

#include "SubParagraph_29_4_1.cpp"
#include "SubParagraph_29_4_2.cpp"
#include "SubParagraph_29_4_3.cpp"

inline void paragraph_29_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "The Proxy Pattern" << endl;
		cout << "=================" << endl;
		cout << " 1) Example: Hiding Network Connectivity Issues" << endl;
		cout << " 2) Implementation of a Proxy" << endl;
		cout << " 3) Using a Proxy" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_29_4_1();
			break;
		case 2:
			subParagraph_29_4_2();
			break;
		case 3:
			subParagraph_29_4_3();
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
