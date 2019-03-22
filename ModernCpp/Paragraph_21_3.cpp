#include "pch.h"

//#include "SubParagraph_21_3_1.cpp"
//#include "SubParagraph_21_3_2.cpp"
//#include "SubParagraph_21_3_3.cpp"
//#include "SubParagraph_21_3_4.cpp"
//#include "SubParagraph_21_3_5.cpp"
//#include "SubParagraph_21_3_6.cpp"

inline void paragraph_21_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Low-Level Memory Operations" << endl;
		cout << "===========================" << endl;
		cout << " 1) Pointer Arithmetic" << endl;
		cout << " 2) Custom Memory Management" << endl;
		cout << " 3) Garbage Collection" << endl;
		cout << " 4) Object Pools" << endl;
		cout << " 5) Function Pointers" << endl;
		cout << " 6) Pointers to Methods and Members" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_21_3_1();
			break;
		case 2:
			//subParagraph_21_3_2();
			break;
		case 3:
			//subParagraph_21_3_3();
			break;
		case 4:
			//subParagraph_21_3_4();
			break;
		case 5:
			//subParagraph_21_3_5();
			break;
		case 6:
			//subParagraph_21_3_6();
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
