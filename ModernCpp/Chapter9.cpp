#include "pch.h"

#include "Paragraph_9_1.cpp"
#include "Paragraph_9_2.cpp"
#include "Paragraph_9_3.cpp"
#include "Paragraph_9_4.cpp"
#include "Paragraph_9_5.cpp"
#include "Paragraph_9_6.cpp"
#include "Paragraph_9_7.cpp"
#include "Paragraph_9_8.cpp"

inline void chapter9() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 9, Understanding C++ Quirks and Oddities" << endl;
		cout << "================================================" << endl;
		cout << " 1) References" << endl;
		cout << " 2) Keyword Confusion" << endl;
		cout << " 3) Types and Casts" << endl;
		cout << " 4) Scope Resolution" << endl;
		cout << " 5) C++11" << endl;
		cout << " 6) Header Files" << endl;
		cout << " 7) C Utilities" << endl;
		cout << " 8) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_9_1();
			break;
		case 2:
			paragraph_9_2();
			break;
		case 3:
			paragraph_9_3();
			break;
		case 4:
			paragraph_9_4();
			break;
		case 5:
			paragraph_9_5();
			break;
		case 6:
			paragraph_9_6();
			break;
		case 7:
			paragraph_9_7();
			break;
		case 8:
			paragraph_9_8();
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
