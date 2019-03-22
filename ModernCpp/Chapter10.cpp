#include "pch.h"

#include "Paragraph_10_1.cpp"
#include "Paragraph_10_2.cpp"
#include "Paragraph_10_3.cpp"
#include "Paragraph_10_4.cpp"
#include "Paragraph_10_5.cpp"
#include "Paragraph_10_6.cpp"
#include "Paragraph_10_7.cpp"

inline void chapter10() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 10, Handling Errors" << endl;
		cout << "===========================" << endl;
		cout << " 1) Errors and Exceptions" << endl;
		cout << " 2) Exception Mechanics" << endl;
		cout << " 3) Exceptions and Polymorphism" << endl;
		cout << " 4) Stack Unwinding and Cleanup" << endl;
		cout << " 5) Common Error-Handling Issues" << endl;
		cout << " 6) Putting It All Together" << endl;
		cout << " 7) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_10_1();
			break;
		case 2:
			paragraph_10_2();
			break;
		case 3:
			paragraph_10_3();
			break;
		case 4:
			paragraph_10_4();
			break;
		case 5:
			paragraph_10_5();
			break;
		case 6:
			paragraph_10_6();
			break;
		case 7:
			paragraph_10_7();
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
