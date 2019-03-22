#include "pch.h"

#include "Paragraph_11_1.cpp"
#include "Paragraph_11_2.cpp"
#include "Paragraph_11_3.cpp"

inline void chapter11() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 11, Delving into the Standard Library" << endl;
		cout << "=============================================" << endl;
		cout << " 1) Coding Principles" << endl;
		cout << " 2) Overview of the C++ Standard Library" << endl;
		cout << " 3) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_11_1();
			break;
		case 2:
			paragraph_11_2();
			break;
		case 3:
			paragraph_11_3();
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
