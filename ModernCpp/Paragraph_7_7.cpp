#include "pch.h"

//#include "SubParagraph_7_7_1.cpp"
//#include "SubParagraph_7_7_2.cpp"
//#include "SubParagraph_7_7_3.cpp"
//#include "SubParagraph_7_7_4.cpp"

inline void paragraph_7_7() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Operator Overloading" << endl;
		cout << "====================" << endl;
		cout << " 1) Example: Implementing Addition for Spreadsheet Cells" << endl;
		cout << " 2) Overloading Arithmetic Operators" << endl;
		cout << " 3) Overloading Comparison Operators" << endl;
		cout << " 4) Building Types with Operator Overloading" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_7_7_1();
			break;
		case 2:
			//subParagraph_7_7_2();
			break;
		case 3:
			//subParagraph_7_7_3();
			break;
		case 4:
			//subParagraph_7_7_4();
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
