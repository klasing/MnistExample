#include "pch.h"

#include "Paragraph_27_1.cpp"
#include "Paragraph_27_2.cpp"
#include "Paragraph_27_3.cpp"
#include "Paragraph_27_4.cpp"
#include "Paragraph_27_5.cpp"
#include "Paragraph_27_6.cpp"

inline void chapter27() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 27, Conquering Debugging" << endl;
		cout << "================================" << endl;
		cout << " 1) The Fundamental Law of Debugging" << endl;
		cout << " 2) Bug Taxanomies" << endl;
		cout << " 3) Avoiding Bugs" << endl;
		cout << " 4) Planning for Bugs" << endl;
		cout << " 5) Debugging Techniques" << endl;
		cout << " 6) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_27_1();
			break;
		case 2:
			paragraph_27_2();
			break;
		case 3:
			paragraph_27_3();
			break;
		case 4:
			paragraph_27_4();
			break;
		case 5:
			paragraph_27_5();
			break;
		case 6:
			paragraph_27_6();
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
