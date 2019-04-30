#include "pch.h"

#include "SubParagraph_5_2_1.cpp"
#include "SubParagraph_5_2_2.cpp"
#include "SubParagraph_5_2_3.cpp"

inline void paragraph_5_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Documenting Your Code" << endl;
		cout << "=====================" << endl;
		cout << " 1) Reasons to Write Comments" << endl;
		cout << " 2) Commenting Styles" << endl;
		cout << " 3) Comments in This Book" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_5_2_1();
			break;
		case 2:
			subParagraph_5_2_2();
			break;
		case 3:
			subParagraph_5_2_3();
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
