#include "pch.h"

#include "Paragraph_26_1.cpp"
#include "Paragraph_26_2.cpp"
#include "Paragraph_26_3.cpp"
#include "Paragraph_26_4.cpp"
#include "Paragraph_26_5.cpp"

inline void chapter26() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 26, Becoming Adept at Testing" << endl;
		cout << "=====================================" << endl;
		cout << " 1) Quality Control" << endl;
		cout << " 2) Unit Testing" << endl;
		cout << " 3) Higher-Level Testing" << endl;
		cout << " 4) Tips for Succesful Testing" << endl;
		cout << " 5) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_26_1();
			break;
		case 2:
			paragraph_26_2();
			break;
		case 3:
			paragraph_26_3();
			break;
		case 4:
			paragraph_26_4();
			break;
		case 5:
			paragraph_26_5();
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
