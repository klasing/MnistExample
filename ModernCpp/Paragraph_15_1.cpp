#include "pch.h"

#include "SubParagraph_15_1_1.cpp"
#include "SubParagraph_15_1_2.cpp"
#include "SubParagraph_15_1_3.cpp"
#include "SubParagraph_15_1_4.cpp"
#include "SubParagraph_15_1_5.cpp"

inline void paragraph_15_1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Using Streams" << endl;
		cout << "=============" << endl;
		cout << " 1) What Is a Stream Anyway?" << endl;
		cout << " 2) Stream Sources and Destinations" << endl;
		cout << " 3) Output with Streams" << endl;
		cout << " 4) Input with Streams" << endl;
		cout << " 5) Input and Output with Objects" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_15_1_1();
			break;
		case 2:
			subParagraph_15_1_2();
			break;
		case 3:
			subParagraph_15_1_3();
			break;
		case 4:
			subParagraph_15_1_4();
			break;
		case 5:
			subParagraph_15_1_5();
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
