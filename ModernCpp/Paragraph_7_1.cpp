#include "pch.h"

//#include "SubParagraph_7_1_1.cpp"
//#include "SubParagraph_7_1_2.cpp"
//#include "SubParagraph_7_1_3.cpp"

inline void paragraph_7_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Dynamic Memory Allocation in Objects" << endl;
		cout << "====================================" << endl;
		cout << " 1) The Spreadsheet Class" << endl;
		cout << " 2) Freeing Memory with Destructors" << endl;
		cout << " 3) Handling Copying and Assignment" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_7_1_1();
			break;
		case 2:
			//subParagraph_7_1_2();
			break;
		case 3:
			//subParagraph_7_1_3();
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
