#include "pch.h"

#include "SubParagraph_12_1_1.cpp"
#include "SubParagraph_12_1_2.cpp"
#include "SubParagraph_12_1_3.cpp"
#include "SubParagraph_12_1_4.cpp"

inline void paragraph_12_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Containers Overview" << endl;
		cout << "===================" << endl;
		cout << " 1) Requirements on Elements" << endl;
		cout << " 2) Exception and Error Checking" << endl;
		cout << " 3) Iterators" << endl;
		cout << " 4) C++11 Changes" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_12_1_1();
			break;
		case 2:
			subParagraph_12_1_2();
			break;
		case 3:
			subParagraph_12_1_3();
			break;
		case 4:
			subParagraph_12_1_4();
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
