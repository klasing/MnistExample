#include "pch.h"

#include "Paragraph_7_1.cpp"
#include "Paragraph_7_2.cpp"
#include "Paragraph_7_3.cpp"
#include "Paragraph_7_4.cpp"
#include "Paragraph_7_5.cpp"
#include "Paragraph_7_6.cpp"
#include "Paragraph_7_7.cpp"
#include "Paragraph_7_8.cpp"
#include "Paragraph_7_9.cpp"

inline void chapter7() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 7, Mastering Classes and Objects" << endl;
		cout << "========================================" << endl;
		cout << " 1) Dynamic Memory Allocation in Objects" << endl;
		cout << " 2) Different Kinds of Data Members" << endl;
		cout << " 3) More about Methods" << endl;
		cout << " 4) Nested Classes" << endl;
		cout << " 5) Enumerated Types Inside Classes" << endl;
		cout << " 6) Friends" << endl;
		cout << " 7) Operator Overloading" << endl;
		cout << " 8) Building Stable Interfaces" << endl;
		cout << " 9) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_7_1();
			break;
		case 2:
			paragraph_7_2();
			break;
		case 3:
			paragraph_7_3();
			break;
		case 4:
			paragraph_7_4();
			break;
		case 5:
			paragraph_7_5();
			break;
		case 6:
			paragraph_7_6();
			break;
		case 7:
			paragraph_7_7();
			break;
		case 8:
			paragraph_7_8();
			break;
		case 9:
			paragraph_7_9();
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
