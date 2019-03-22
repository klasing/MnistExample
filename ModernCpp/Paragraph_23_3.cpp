#include "pch.h"

//#include "SubParagraph_23_3_1.cpp"
//#include "SubParagraph_23_3_2.cpp"
//#include "SubParagraph_23_3_3.cpp"
//#include "SubParagraph_23_3_4.cpp"

inline void paragraph_23_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Software Engineering Methodologies" << endl;
		cout << "==================================" << endl;
		cout << " 1) Agile" << endl;
		cout << " 2) Scrum" << endl;
		cout << " 3) Extreme Programming (XP)" << endl;
		cout << " 4) Software Triage" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_23_3_1();
			break;
		case 2:
			//subParagraph_23_3_1();
			break;
		case 3:
			//subParagraph_23_3_3();
			break;
		case 4:
			//subParagraph_23_3_4();
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
