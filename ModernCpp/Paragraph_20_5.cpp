#include "pch.h"

//#include "SubParagraph_20_5_1.cpp"
//#include "SubParagraph_20_5_2.cpp"
//#include "SubParagraph_20_5_3.cpp"

inline void paragraph_20_5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Type Inference" << endl;
		cout << "==============" << endl;
		cout << " 1) The auto Keyword" << endl;
		cout << " 2) The decltype Keyword" << endl;
		cout << " 3) auto and decltype with Templates" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_20_5_1();
			break;
		case 2:
			//subParagraph_20_5_2();
			break;
		case 3:
			//subParagraph_20_5_3();
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
