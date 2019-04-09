#include "pch.h"

#include "SubParagraph_13_4_1.cpp"
#include "SubParagraph_13_4_2.cpp"
#include "SubParagraph_13_4_3.cpp"
#include "SubParagraph_13_4_4.cpp"
#include "SubParagraph_13_4_5.cpp"

inline void paragraph_13_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Algorithm Details" << endl;
		cout << "=================" << endl;
		cout << " 1) Utility Algorithms" << endl;
		cout << " 2) Non-Modifying Algorithms" << endl;
		cout << " 3) Modifying Algorithms" << endl;
		cout << " 4) Sorting Algorithms" << endl;
		cout << " 5) Set Algorithms" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_13_4_1();
			break;
		case 2:
			subParagraph_13_4_2();
			break;
		case 3:
			subParagraph_13_4_3();
			break;
		case 4:
			subParagraph_13_4_4();
			break;
		case 5:
			subParagraph_13_4_5();
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
