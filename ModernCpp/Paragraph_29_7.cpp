#include "pch.h"

//#include "SubParagraph_29_7_1.cpp"
//#include "SubParagraph_29_7_2.cpp"
//#include "SubParagraph_29_7_3.cpp"

inline void paragraph_29_7() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "The Chain of Responsibility Pattern" << endl;
		cout << "===================================" << endl;
		cout << " 1) Example: Event Handling" << endl;
		cout << " 2) Implementation of a Chain of Responsibility" << endl;
		cout << " 3) Using a Chain of Responsebility" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_29_7_1();
			break;
		case 2:
			//subParagraph_29_7_2();
			break;
		case 3:
			//subParagraph_29_7_3();
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
