#include "pch.h"

//#include "SubParagraph_13_3_1.cpp"
//#include "SubParagraph_13_3_2.cpp"
//#include "SubParagraph_13_3_3.cpp"
//#include "SubParagraph_13_3_4.cpp"
//#include "SubParagraph_13_3_5.cpp"
//#include "SubParagraph_13_3_6.cpp"

inline void paragraph_13_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Function Objects" << endl;
		cout << "================" << endl;
		cout << " 1) Arithmetic Fuction Objects" << endl;
		cout << " 2) Comparison Function Objects" << endl;
		cout << " 3) Logical Function Objects" << endl;
		cout << " 4) Bitwise Function Objects" << endl;
		cout << " 5) Function Object Adapters" << endl;
		cout << " 6) Writing Your Own Function Objects" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_13_3_1();
			break;
		case 2:
			//subParagraph_13_3_2();
			break;
		case 3:
			//subParagraph_13_3_3();
			break;
		case 4:
			//subParagraph_13_3_4();
			break;
		case 5:
			//subParagraph_13_3_5();
			break;
		case 6:
			//subParagraph_13_3_6();
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
