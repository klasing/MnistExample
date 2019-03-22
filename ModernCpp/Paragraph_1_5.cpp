#include "pch.h"

//#include "SubParagraph_1_5_1.cpp"
//#include "SubParagraph_1_5_2.cpp"
//#include "SubParagraph_1_5_3.cpp"
//#include "SubParagraph_1_5_4.cpp"
//#include "SubParagraph_1_5_5.cpp"

inline void paragraph_1_5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Your First Useful C++ Program" << endl;
		cout << "=============================" << endl;
		cout << " 1) An Employee Records System" << endl;
		cout << " 2) The Employee Class" << endl;
		cout << " 3) The Database Class" << endl;
		cout << " 4) The User Interface" << endl;
		cout << " 5) Evaluating the Program" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_1_5_1();
			break;
		case 2:
			//subParagraph_1_5_2();
			break;
		case 3:
			//subParagraph_1_5_3();
			break;
		case 4:
			//subParagraph_1_5_4();
			break;
		case 5:
			//subParagraph_1_5_5();
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
