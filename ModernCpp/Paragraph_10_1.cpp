#include "pch.h"

//#include "SubParagraph_10_1_1.cpp"
//#include "SubParagraph_10_1_2.cpp"
//#include "SubParagraph_10_1_3.cpp"
//#include "SubParagraph_10_1_4.cpp"

inline void paragraph_10_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Errors and Exceptions" << endl;
		cout << "=====================" << endl;
		cout << " 1) What Are Exceptions Anyway?" << endl;
		cout << " 2) Why Exceptions in C++ Are a Good Thing" << endl;
		cout << " 3) Why Exceptions in C++ Are a Bad Thing" << endl;
		cout << " 4) Our Recommendation" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_10_1_1();
			break;
		case 2:
			//subParagraph_10_1_2();
			break;
		case 3:
			//subParagraph_10_1_3();
			break;
		case 4:
			//subParagraph_10_1_4();
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
