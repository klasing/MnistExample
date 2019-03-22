#include "pch.h"

#include "Paragraph_18_1.cpp"
#include "Paragraph_18_2.cpp"
#include "Paragraph_18_3.cpp"
#include "Paragraph_18_4.cpp"
#include "Paragraph_18_5.cpp"
#include "Paragraph_18_6.cpp"
#include "Paragraph_18_7.cpp"
#include "Paragraph_18_8.cpp"
#include "Paragraph_18_9.cpp"
#include "Paragraph_18_10.cpp"

inline void chapter18() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 18, Overloading C++ Operators" << endl;
		cout << "=====================================" << endl;
		cout << " 1) Overview of Operator Overloading" << endl;
		cout << " 2) Overloading the Arithmetic Operators" << endl;
		cout << " 3) Overloading the Bitwise and Binary Logical Operators" << endl;
		cout << " 4) Overloading the Insertion and Extraction Operators" << endl;
		cout << " 5) Overloading the Subscripting Operator" << endl;
		cout << " 6) Overloading the Function Call Operator" << endl;
		cout << " 7) Overloading the Dereferencing Operators" << endl;
		cout << " 8) Writing Conversion Operators" << endl;
		cout << " 9) Overloading the Memory Allocation and Deallocation Operators" << endl;
		cout << "10) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_18_1();
			break;
		case 2:
			paragraph_18_2();
			break;
		case 3:
			paragraph_18_3();
			break;
		case 4:
			paragraph_18_4();
			break;
		case 5:
			paragraph_18_5();
			break;
		case 6:
			paragraph_18_6();
			break;
		case 7:
			paragraph_18_7();
			break;
		case 8:
			paragraph_18_8();
			break;
		case 9:
			paragraph_18_9();
			break;
		case 10:
			paragraph_18_10();
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
