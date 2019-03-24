#include "pch.h"

#include "Paragraph_14_1.cpp"
#include "Paragraph_14_2.cpp"
#include "Paragraph_14_3.cpp"
#include "Paragraph_14_4.cpp"

inline void chapter14() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 14, Using Strings and Regular Expressions" << endl;
		cout << "=================================================" << endl;
		cout << " 1) Dynamic Strings" << endl;
		cout << " 2) Localization" << endl;
		cout << " 3) Regular Expressions" << endl;
		cout << " 4) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_14_1();
			break;
		case 2:
			paragraph_14_2();
			break;
		case 3:
			paragraph_14_3();
			break;
		case 4:
			paragraph_14_4();
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
