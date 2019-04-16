#include "pch.h"

#include "SubParagraph_21_5_1.cpp"
#include "SubParagraph_21_5_2.cpp"
#include "SubParagraph_21_5_3.cpp"
#include "SubParagraph_21_5_4.cpp"

inline void paragraph_21_5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Common Memory Pitfalls" << endl;
		cout << "======================" << endl;
		cout << " 1) Underallocating Strings" << endl;
		cout << " 2) Memory Leaks" << endl;
		cout << " 3) Double-Deleting and Invalid Pointers" << endl;
		cout << " 4) Accessing Out-of-Bounds Memory" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_21_5_1();
			break;
		case 2:
			subParagraph_21_5_2();
			break;
		case 3:
			subParagraph_21_5_3();
			break;
		case 4:
			subParagraph_21_5_4();
			break;
		case 5:
			//subParagraph_21_5_5();
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
