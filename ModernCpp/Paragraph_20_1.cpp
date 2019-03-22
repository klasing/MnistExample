#include "pch.h"

//#include "SubParagraph_20_1_1.cpp"
//#include "SubParagraph_20_1_2.cpp"
//#include "SubParagraph_20_1_3.cpp"

inline void paragraph_20_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "More about Template Parameters" << endl;
		cout << "==============================" << endl;
		cout << " 1) More about Template Type Parameters" << endl;
		cout << " 2) Introducing Template Template Parameters" << endl;
		cout << " 3) More about Non-Type Template Parameters" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_20_1_1();
			break;
		case 2:
			//subParagraph_20_1_2();
			break;
		case 3:
			//subParagraph_20_1_3();
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
