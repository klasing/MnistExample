#include "pch.h"

//#include "SubParagraph_15_3_1.cpp"
//#include "SubParagraph_15_3_2.cpp"

inline void paragraph_15_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "File Streams" << endl;
		cout << "============" << endl;
		cout << " 1) Jumping around with seek() and tell()" << endl;
		cout << " 2) Linking Streams Together" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_15_3_1();
			break;
		case 2:
			//subParagraph_15_3_2();
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
