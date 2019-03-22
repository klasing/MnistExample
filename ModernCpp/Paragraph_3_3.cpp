#include "pch.h"

//#include "SubParagraph_3_3_1.cpp"
//#include "SubParagraph_3_3_2.cpp"

inline void paragraph_3_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Living in a World of Objects" << endl;
		cout << "============================" << endl;
		cout << " 1) Overobjectification" << endl;
		cout << " 2) Overly General Objects" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_3_3_1();
			break;
		case 2:
			//subParagraph_3_3_2();
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
