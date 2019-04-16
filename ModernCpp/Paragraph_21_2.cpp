#include "pch.h"

#include "SubParagraph_21_2_1.cpp"
#include "SubParagraph_21_2_2.cpp"

inline void paragraph_21_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Array-Pointer Duality" << endl;
		cout << "=====================" << endl;
		cout << " 1) Arrays Are Pointers!" << endl;
		cout << " 2) Not All Pointers Are Arrays!" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_21_2_1();
			break;
		case 2:
			subParagraph_21_2_2();
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
