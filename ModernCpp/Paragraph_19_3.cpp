#include "pch.h"

//#include "SubParagraph_19_3_1.cpp"
//#include "SubParagraph_19_3_2.cpp"
//#include "SubParagraph_19_3_3.cpp"

inline void paragraph_19_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Function Templates" << endl;
		cout << "==================" << endl;
		cout << " 1) Function Template Specialization" << endl;
		cout << " 2) Function Template Overloading" << endl;
		cout << " 3) Friend Function Templates of Class Templates" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_19_3_1();
			break;
		case 2:
			//subParagraph_19_3_2();
			break;
		case 3:
			//subParagraph_19_3_3();
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
