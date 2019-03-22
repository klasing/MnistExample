#include "pch.h"

//#include "SubParagraph_27_4_1.cpp"
//#include "SubParagraph_27_4_2.cpp"
//#include "SubParagraph_27_4_3.cpp"
//#include "SubParagraph_27_4_4.cpp"

inline void paragraph_27_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Planning for Bugs" << endl;
		cout << "=================" << endl;
		cout << " 1) Error Logging" << endl;
		cout << " 2) Debug Traces" << endl;
		cout << " 3) Asserts" << endl;
		cout << " 4) Static Asserts" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_27_4_1();
			break;
		case 2:
			//subParagraph_27_4_2();
			break;
		case 3:
			//subParagraph_27_4_3();
			break;
		case 4:
			//subParagraph_27_4_4();
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
