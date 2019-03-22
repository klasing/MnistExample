#include "pch.h"

//#include "SubParagraph_9_1_1.cpp"
//#include "SubParagraph_9_1_2.cpp"
//#include "SubParagraph_9_1_3.cpp"
//#include "SubParagraph_9_1_4.cpp"
//#include "SubParagraph_9_1_5.cpp"
//#include "SubParagraph_9_1_6.cpp"

inline void paragraph_9_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "References" << endl;
		cout << "==========" << endl;
		cout << " 1) Reference Variables" << endl;
		cout << " 2) Reference Data Members" << endl;
		cout << " 3) Reference Parameters" << endl;
		cout << " 4) Reference Return Values" << endl;
		cout << " 5) Deciding between References and Pointers" << endl;
		cout << " 6) Rvalue References" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_9_1_1();
			break;
		case 2:
			//subParagraph_9_1_2();
			break;
		case 3:
			//subParagraph_9_1_3();
			break;
		case 4:
			//subParagraph_9_1_4();
			break;
		case 5:
			//subParagraph_9_1_5();
			break;
		case 6:
			//subParagraph_9_1_6();
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
