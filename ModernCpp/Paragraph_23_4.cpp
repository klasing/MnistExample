#include "pch.h"

//#include "SubParagraph_23_4_1.cpp"
//#include "SubParagraph_23_4_2.cpp"
//#include "SubParagraph_23_4_3.cpp"
//#include "SubParagraph_23_4_4.cpp"

inline void paragraph_23_4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Building Your Own Process and Methodology" << endl;
		cout << "=========================================" << endl;
		cout << " 1) Be Open to New Ideas" << endl;
		cout << " 2) Bring New Ideas to the Table" << endl;
		cout << " 3) Recognize What Works and What Doesn't Work" << endl;
		cout << " 4) Don't Be a Renegade" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_23_4_1();
			break;
		case 2:
			//subParagraph_23_4_2();
			break;
		case 3:
			//subParagraph_23_4_3();
			break;
		case 4:
			//subParagraph_23_4_4();
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
