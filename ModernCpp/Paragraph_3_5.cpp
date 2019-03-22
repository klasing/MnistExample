#include "pch.h"

//#include "SubParagraph_3_5_1.cpp"
//#include "SubParagraph_3_5_2.cpp"
//#include "SubParagraph_3_5_3.cpp"

inline void paragraph_3_5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Abstraction" << endl;
		cout << "===========" << endl;
		cout << " 1) Interface versus Implementation" << endl;
		cout << " 2) Deciding on an Exposed Interface" << endl;
		cout << " 3) Designing a Successful Abstraction" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_3_5_1();
			break;
		case 2:
			//subParagraph_3_5_2();
			break;
		case 3:
			//subParagraph_3_5_3();
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
