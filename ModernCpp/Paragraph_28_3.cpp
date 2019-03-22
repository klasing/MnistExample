#include "pch.h"

//#include "SubParagraph_28_3_1.cpp"
//#include "SubParagraph_28_3_2.cpp"

inline void paragraph_28_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Object-Oriented Frameworks" << endl;
		cout << "==========================" << endl;
		cout << " 1) Working with Frameworks" << endl;
		cout << " 2) The Model-View-Controller Paradigm" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_28_3_1();
			break;
		case 2:
			//subParagraph_28_3_2();
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
