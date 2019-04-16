#include "pch.h"

#include "SubParagraph_18_1_1.cpp"
#include "SubParagraph_18_1_2.cpp"
#include "SubParagraph_18_1_3.cpp"
#include "SubParagraph_18_1_4.cpp"
#include "SubParagraph_18_1_5.cpp"
#include "SubParagraph_18_1_6.cpp"

inline void paragraph_18_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Overview of Operator Overloading" << endl;
		cout << "================================" << endl;
		cout << " 1) Why Overload Operators?" << endl;
		cout << " 2) Limitations to Operator Overloading" << endl;
		cout << " 3) Choices in Operator Overloading" << endl;
		cout << " 4) Operators You shouldn't Overload" << endl;
		cout << " 5) Summary of Overloadable Operators" << endl;
		cout << " 6) Rvalue References" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_18_1_1();
			break;
		case 2:
			subParagraph_18_1_2();
			break;
		case 3:
			subParagraph_18_1_3();
			break;
		case 4:
			subParagraph_18_1_4();
			break;
		case 5:
			subParagraph_18_1_5();
			break;
		case 6:
			subParagraph_18_1_6();
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
