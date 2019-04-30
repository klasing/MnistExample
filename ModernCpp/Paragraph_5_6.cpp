#include "pch.h"

#include "SubParagraph_5_6_1.cpp"
#include "SubParagraph_5_6_2.cpp"
#include "SubParagraph_5_6_3.cpp"

inline void paragraph_5_6() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Formatting" << endl;
		cout << "==========" << endl;
		cout << " 1) The Curly Brace Alignment Debate" << endl;
		cout << " 2) Coming to Blows over Spaces and Parenthesis" << endl;
		cout << " 3) Spacing and Tabs" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_5_6_1();
			break;
		case 2:
			subParagraph_5_6_2();
			break;
		case 3:
			subParagraph_5_6_3();
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
