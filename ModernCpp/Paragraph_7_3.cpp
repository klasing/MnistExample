#include "pch.h"

//#include "SubParagraph_7_3_1.cpp"
//#include "SubParagraph_7_3_2.cpp"
//#include "SubParagraph_7_3_3.cpp"
//#include "SubParagraph_7_3_4.cpp"
//#include "SubParagraph_7_3_5.cpp"

inline void paragraph_7_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "More about Methods" << endl;
		cout << "==================" << endl;
		cout << " 1) static Methods" << endl;
		cout << " 2) const Methods" << endl;
		cout << " 3) Method Overloading" << endl;
		cout << " 4) Default Parameters" << endl;
		cout << " 5) Inline Methods" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_7_3_1();
			break;
		case 2:
			//subParagraph_7_3_2();
			break;
		case 3:
			//subParagraph_7_3_3();
			break;
		case 4:
			//subParagraph_7_3_4();
			break;
		case 5:
			//subParagraph_7_3_5();
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
