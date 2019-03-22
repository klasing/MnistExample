#include "pch.h"

//#include "SubParagraph_4_2_1.cpp"
//#include "SubParagraph_4_2_2.cpp"
//#include "SubParagraph_4_2_3.cpp"
//#include "SubParagraph_4_2_4.cpp"

inline void paragraph_4_2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "How to Design Reusable Code" << endl;
		cout << "===========================" << endl;
		cout << " 1) Use Abstraction" << endl;
		cout << " 2) Structure Your Code for Optimal Reuse" << endl;
		cout << " 3) Design Usable Interfaces" << endl;
		cout << " 4) Reconciling Generality and Ease of Use" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_4_2_1();
			break;
		case 2:
			//subParagraph_4_2_2();
			break;
		case 3:
			//subParagraph_4_2_3();
			break;
		case 4:
			//subParagraph_4_2_4();
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
