#include "pch.h"

//#include "SubParagraph_21_4_1.cpp"
//#include "SubParagraph_21_4_2.cpp"
//#include "SubParagraph_21_4_3.cpp"

inline void paragraph_21_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Smart Pointers" << endl;
		cout << "==============" << endl;
		cout << " 1) The Old Deprecated auto_ptr" << endl;
		cout << " 2) The new C++11 Smart Pointers" << endl;
		cout << " 3) Writing Your Own Smart Pointer Class" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_21_4_1();
			break;
		case 2:
			//subParagraph_21_4_2();
			break;
		case 3:
			//subParagraph_21_4_3();
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
