#include "pch.h"

#include "SubParagraph_1_1_1.cpp"
#include "SubParagraph_1_1_2.cpp"
#include "SubParagraph_1_1_3.cpp"
#include "SubParagraph_1_1_4.cpp"
#include "SubParagraph_1_1_5.cpp"
#include "SubParagraph_1_1_6.cpp"
#include "SubParagraph_1_1_7.cpp"
#include "SubParagraph_1_1_8.cpp"
#include "SubParagraph_1_1_9.cpp"
#include "SubParagraph_1_1_10.cpp"

inline void paragraph_1_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "The Basics of C++" << endl;
		cout << "=================" << endl;
		cout << " 1) The Obligatory Hello World" << endl;
		cout << " 2) Namespaces" << endl;
		cout << " 3) Variables" << endl;
		cout << " 4) Operators" << endl;
		cout << " 5) Types" << endl;
		cout << " 6) Conditionals" << endl;
		cout << " 7) Loops" << endl;
		cout << " 8) Arrays" << endl;
		cout << " 9) Functions" << endl;
		cout << "10) Those Are the Basics" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_1_1_1();
			break;
		case 2:
			subParagraph_1_1_2();
			break;
		case 3:
			subParagraph_1_1_3();
			break;
		case 4:
			subParagraph_1_1_4();
			break;
		case 5:
			subParagraph_1_1_5();
			break;
		case 6:
			subParagraph_1_1_6();
			break;
		case 7:
			subParagraph_1_1_7();
			break;
		case 8:
			subParagraph_1_1_8();
			break;
		case 9:
			subParagraph_1_1_9();
			break;
		case 10:
			subParagraph_1_1_10();
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
