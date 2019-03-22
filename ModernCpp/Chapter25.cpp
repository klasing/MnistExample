#include "pch.h"

#include "Paragraph_25_1.cpp"
#include "Paragraph_25_2.cpp"
#include "Paragraph_25_3.cpp"

inline void chapter25() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 25, Developing Cross-Platform and Cross-Language Applications" << endl;
		cout << "=====================================================================" << endl;
		cout << " 1) Cross-Platform Development" << endl;
		cout << " 2) Cross-Language Development" << endl;
		cout << " 3) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_25_1();
			break;
		case 2:
			paragraph_25_2();
			break;
		case 3:
			paragraph_25_3();
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
