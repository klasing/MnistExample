#include "pch.h"

#include "SubParagraph_1_2_1.cpp"
#include "SubParagraph_1_2_2.cpp"
#include "SubParagraph_1_2_3.cpp"
#include "SubParagraph_1_2_4.cpp"
#include "SubParagraph_1_2_5.cpp"

inline void paragraph_1_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Diving Deeper into C++" << endl;
		cout << "======================" << endl;
		cout << " 1) Pointers and Dynamic Memory" << endl;
		cout << " 2) Strings in C++" << endl;
		cout << " 3) References" << endl;
		cout << " 4) Exceptions" << endl;
		cout << " 5) The Many Uses of const" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_1_2_1();
			break;
		case 2:
			subParagraph_1_2_2();
			break;
		case 3:
			subParagraph_1_2_3();
			break;
		case 4:
			subParagraph_1_2_4();
			break;
		case 5:
			subParagraph_1_2_5();
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
