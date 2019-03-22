#include "pch.h"

//#include "SubParagraph_18_2_1.cpp"
//#include "SubParagraph_18_2_2.cpp"

inline void paragraph_18_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Overloading the Arithmetic Operators" << endl;
		cout << "====================================" << endl;
		cout << " 1) Overloading Unary Minus and Unary Plus" << endl;
		cout << " 2) Overloading Increment and Decrement" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_18_2_1();
			break;
		case 2:
			//subParagraph_18_2_2();
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
