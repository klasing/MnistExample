#include "pch.h"

//#include "SubParagraph_16_3_1.cpp"
//#include "SubParagraph_16_3_2.cpp"
//#include "SubParagraph_16_3_3.cpp"

inline void paragraph_16_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "The Chrono Library" << endl;
		cout << "==================" << endl;
		cout << " 1) Duration" << endl;
		cout << " 2) Clock" << endl;
		cout << " 3) Time Point" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_16_3_1();
			break;
		case 2:
			//subParagraph_16_3_2();
			break;
		case 3:
			//subParagraph_16_3_3();
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
