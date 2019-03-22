#include "pch.h"

//#include "SubParagraph_22_3_1.cpp"
//#include "SubParagraph_22_3_2.cpp"
//#include "SubParagraph_22_3_3.cpp"
//#include "SubParagraph_22_3_4.cpp"
//#include "SubParagraph_22_3_5.cpp"
//#include "SubParagraph_22_3_6.cpp"
//#include "SubParagraph_22_3_7.cpp"
//#include "SubParagraph_22_3_8.cpp"

inline void paragraph_22_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Threads" << endl;
		cout << "=======" << endl;
		cout << " 1) Thread with Function Pointer" << endl;
		cout << " 2) Thread with Function Object" << endl;
		cout << " 3) Thread with Lambda" << endl;
		cout << " 4) Thread with Member Function" << endl;
		cout << " 5) Thread Local Storage" << endl;
		cout << " 6) Cancelling Threads" << endl;
		cout << " 7) Retrieving Results from Threads" << endl;
		cout << " 8) Copying and Rethrowing Exceptions" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_22_3_1();
			break;
		case 2:
			//subParagraph_22_3_2();
			break;
		case 3:
			//subParagraph_22_3_3();
			break;
		case 4:
			//subParagraph_22_3_4();
			break;
		case 5:
			//subParagraph_22_3_5();
			break;
		case 6:
			//subParagraph_22_3_6();
			break;
		case 7:
			//subParagraph_22_3_7();
			break;
		case 8:
			//subParagraph_22_3_8();
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
