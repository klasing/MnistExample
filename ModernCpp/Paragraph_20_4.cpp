#include "pch.h"

//#include "SubParagraph_20_4_1.cpp"
//#include "SubParagraph_20_4_2.cpp"

inline void paragraph_20_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Template Recursion" << endl;
		cout << "==================" << endl;
		cout << " 1) An N-Dimensiononal Grid: First Attempt" << endl;
		cout << " 2) A Real N-Dimensional Grid" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_20_4_1();
			break;
		case 2:
			//subParagraph_20_4_2();
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
