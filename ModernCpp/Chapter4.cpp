#include "pch.h"

#include "Paragraph_4_1.cpp"
#include "Paragraph_4_2.cpp"
#include "Paragraph_4_3.cpp"

inline void chapter4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 4, Designing for Reuse" << endl;
		cout << "==============================" << endl;
		cout << " 1) The Reuse Philosophy" << endl;
		cout << " 2) How to Design Reusable Code" << endl;
		cout << " 3) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_4_1();
			break;
		case 2:
			paragraph_4_2();
			break;
		case 3:
			paragraph_4_3();
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
