#include "pch.h"

//#include "SubParagraph_25_1_1.cpp"
//#include "SubParagraph_25_1_2.cpp"
//#include "SubParagraph_25_1_3.cpp"

inline void paragraph_25_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Cross-Platform Development" << endl;
		cout << "==========================" << endl;
		cout << " 1) Architecture Issues" << endl;
		cout << " 2) Implementation Issues" << endl;
		cout << " 3) Platform-Specific Features" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_25_1_1();
			break;
		case 2:
			//subParagraph_25_1_2();
			break;
		case 3:
			//subParagraph_25_1_3();
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
