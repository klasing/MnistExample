#include "pch.h"

//#include "SubParagraph_9_3_1.cpp"
//#include "SubParagraph_9_3_2.cpp"
//#include "SubParagraph_9_3_3.cpp"
//#include "SubParagraph_9_3_4.cpp"

inline void paragraph_9_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Types and Casts" << endl;
		cout << "===============" << endl;
		cout << " 1) typedefs" << endl;
		cout << " 2) typedefs for Function Pointers" << endl;
		cout << " 3) Type Aliases" << endl;
		cout << " 4) Casts" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_9_3_1();
			break;
		case 2:
			//subParagraph_9_3_2();
			break;
		case 3:
			//subParagraph_9_3_3();
			break;
		case 4:
			//subParagraph_9_3_4();
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
