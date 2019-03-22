#include "pch.h"

//#include "SubParagraph_18_7_1.cpp"
//#include "SubParagraph_18_7_2.cpp"
//#include "SubParagraph_18_7_3.cpp"

inline void paragraph_18_7() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Overloading the Dereferencing Operators" << endl;
		cout << "=======================================" << endl;
		cout << " 1) Implementing operator*" << endl;
		cout << " 2) Implementing operator->" << endl;
		cout << " 3) What in the World is operator ->*?" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_18_7_1();
			break;
		case 2:
			//subParagraph_18_7_2();
			break;
		case 3:
			//subParagraph_18_7_3();
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
