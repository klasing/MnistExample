#include "pch.h"

//#include "SubParagraph_28_1_1.cpp"
//#include "SubParagraph_28_1_2.cpp"
//#include "SubParagraph_28_1_3.cpp"
//#include "SubParagraph_28_1_4.cpp"
//#include "SubParagraph_28_1_5.cpp"
//#include "SubParagraph_28_1_6.cpp"

inline void paragraph_28_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "\"I Can Never Remember How To...\"" << endl;
		cout << "================================" << endl;
		cout << " 1) ... Write a Class" << endl;
		cout << " 2) ... Subclass an Existing Class" << endl;
		cout << " 3) ... Throw and Catch Exceptions" << endl;
		cout << " 4) ... Read from a File" << endl;
		cout << " 5) ... Write to a File" << endl;
		cout << " 6) ... Write a Template Class" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_28_1_1();
			break;
		case 2:
			//subParagraph_28_1_2();
			break;
		case 3:
			//subParagraph_28_1_3();
			break;
		case 4:
			//subParagraph_28_1_4();
			break;
		case 5:
			//subParagraph_28_1_5();
			break;
		case 6:
			//subParagraph_28_1_6();
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
