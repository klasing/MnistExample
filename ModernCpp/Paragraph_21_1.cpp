#include "pch.h"

//#include "SubParagraph_21_1_1.cpp"
//#include "SubParagraph_21_1_2.cpp"
//#include "SubParagraph_21_1_3.cpp"
//#include "SubParagraph_21_1_4.cpp"

inline void paragraph_21_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Working with Dynamic Memory" << endl;
		cout << "===========================" << endl;
		cout << " 1) How to Picture the Model" << endl;
		cout << " 2) Allocation and Deallocation" << endl;
		cout << " 3) Arrays" << endl;
		cout << " 4) Working with pointers" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_21_1_1();
			break;
		case 2:
			//subParagraph_21_1_2();
			break;
		case 3:
			//subParagraph_21_1_3();
			break;
		case 4:
			//subParagraph_21_1_4();
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
