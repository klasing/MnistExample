#include "pch.h"

#include "Paragraph_21_1.cpp"
#include "Paragraph_21_2.cpp"
#include "Paragraph_21_3.cpp"
#include "Paragraph_21_4.cpp"
#include "Paragraph_21_5.cpp"
#include "Paragraph_21_6.cpp"

inline void chapter21() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 21, Effective Memory Management" << endl;
		cout << "=======================================" << endl;
		cout << " 1) Working with Dynamic Memory" << endl;
		cout << " 2) Array-Pointer Duality" << endl;
		cout << " 3) Low-Level Memory Operations" << endl;
		cout << " 4) Smart Pointers" << endl;
		cout << " 5) Common Memory Pitfalls" << endl;
		cout << " 6) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_21_1();
			break;
		case 2:
			paragraph_21_2();
			break;
		case 3:
			paragraph_21_3();
			break;
		case 4:
			paragraph_21_4();
			break;
		case 5:
			paragraph_21_5();
			break;
		case 6:
			paragraph_21_6();
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
