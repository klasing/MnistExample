#include "pch.h"

//#include "SubParagraph_26_1_1.cpp"
//#include "SubParagraph_26_1_2.cpp"
//#include "SubParagraph_26_1_3.cpp"

inline void paragraph_26_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Quality Control" << endl;
		cout << "===============" << endl;
		cout << " 1) Whose Responsibility Is Testing?" << endl;
		cout << " 2) The Life Cycle of a Bug" << endl;
		cout << " 3) Bug-Tracking Tools" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_26_1_1();
			break;
		case 2:
			//subParagraph_26_1_2();
			break;
		case 3:
			//subParagraph_26_1_3();
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
