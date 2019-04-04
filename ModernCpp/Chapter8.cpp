#include "pch.h"

#include "Paragraph_8_1.cpp"
#include "Paragraph_8_2.cpp"
#include "Paragraph_8_3.cpp"
#include "Paragraph_8_4.cpp"
#include "Paragraph_8_5.cpp"
#include "Paragraph_8_6.cpp"
#include "Paragraph_8_7.cpp"

inline void chapter8() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 8, Discovering Inheritance Techniques" << endl;
		cout << "=============================================" << endl;
		cout << " 1) Building Classes with Inheritance" << endl;
		cout << " 2) Inheritance for Reuse" << endl;
		cout << " 3) Respect Your Parents" << endl;
		cout << " 4) Inheritance for Polymorphism" << endl;
		cout << " 5) Multiple Inheritance" << endl;
		cout << " 6) Interesting and Obscure Inheritance Issues" << endl;
		cout << " 7) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_8_1();
			break;
		case 2:
			paragraph_8_2();
			break;
		case 3:
			paragraph_8_3();
			break;
		case 4:
			paragraph_8_4();
			break;
		case 5:
			paragraph_8_5();
			break;
		case 6:
			paragraph_8_6();
			break;
		case 7:
			paragraph_8_7();
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
