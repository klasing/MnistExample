#include "pch.h"

//#include "SubParagraph_2_4_1.cpp"
//#include "SubParagraph_2_4_2.cpp"

inline void paragraph_2_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Two Rules for C++ Design" << endl;
		cout << "========================" << endl;
		cout << " 1) Abstration" << endl;
		cout << " 2) Reuse" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_2_4_1();
			break;
		case 2:
			//subParagraph_2_4_2();
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
