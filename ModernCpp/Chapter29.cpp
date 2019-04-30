#include "pch.h"

#include "Paragraph_29_1.cpp"
#include "Paragraph_29_2.cpp"
#include "Paragraph_29_3.cpp"
#include "Paragraph_29_4.cpp"
#include "Paragraph_29_5.cpp"
#include "Paragraph_29_6.cpp"
#include "Paragraph_29_7.cpp"
#include "Paragraph_29_8.cpp"
#include "Paragraph_29_9.cpp"

inline void chapter29() {
	// goto:
	// https://en.wikipedia.org/wiki/Design_Patterns
	// to learn about all 23 patterns
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 29, Applying Design Patterns" << endl;
		cout << "====================================" << endl;
		cout << " 1) The Iterator Pattern" << endl;
		cout << " 2) The Singleton Pattern" << endl;
		cout << " 3) The Factory Pattern" << endl;
		cout << " 4) The Proxy Pattern" << endl;
		cout << " 5) The Adapter Pattern" << endl;
		cout << " 6) The Decorator Pattern" << endl;
		cout << " 7) The Chain of Responsibility Pattern" << endl;
		cout << " 8) The Observer Pattern" << endl;
		cout << " 9) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_29_1();
			break;
		case 2:
			paragraph_29_2();
			break;
		case 3:
			paragraph_29_3();
			break;
		case 4:
			paragraph_29_4();
			break;
		case 5:
			paragraph_29_5();
			break;
		case 6:
			paragraph_29_6();
			break;
		case 7:
			paragraph_29_7();
			break;
		case 8:
			paragraph_29_8();
			break;
		case 9:
			paragraph_29_9();
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
