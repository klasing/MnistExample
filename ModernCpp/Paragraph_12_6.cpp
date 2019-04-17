#include "pch.h"

#include "SubParagraph_12_6_1.cpp"
#include "SubParagraph_12_6_2.cpp"
#include "SubParagraph_12_6_3.cpp"
#include "SubParagraph_12_6_4.cpp"

inline void paragraph_12_6() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Other Containers" << endl;
		cout << "================" << endl;
		cout << " 1) Standard C-Style Arrays" << endl;
		cout << " 2) Strings" << endl;
		cout << " 3) Streams" << endl;
		cout << " 4) bitset" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_12_6_1();
			break;
		case 2:
			subParagraph_12_6_2();
			break;
		case 3:
			subParagraph_12_6_3();
			break;
		case 4:
			subParagraph_12_6_4();
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
