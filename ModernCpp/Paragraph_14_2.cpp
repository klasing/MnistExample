#include "pch.h"

//#include "SubParagraph_14_2_1.cpp"
//#include "SubParagraph_14_2_2.cpp"
//#include "SubParagraph_14_2_3.cpp"
//#include "SubParagraph_14_2_4.cpp"

inline void paragraph_14_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Localization" << endl;
		cout << "============" << endl;
		cout << " 1) Localization String Literals" << endl;
		cout << " 2) Wide Characters" << endl;
		cout << " 3) Non-Western Character Sets" << endl;
		cout << " 4) Locales and Facets" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_14_2_1();
			break;
		case 2:
			//subParagraph_14_2_2();
			break;
		case 3:
			//subParagraph_14_2_3();
			break;
		case 4:
			//subParagraph_14_2_4();
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
