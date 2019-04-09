#include "pch.h"

#include "SubParagraph_17_3_1.cpp"
#include "SubParagraph_17_3_2.cpp"
#include "SubParagraph_17_3_3.cpp"

inline void paragraph_17_3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Extending the STL" << endl;
		cout << "=================" << endl;
		cout << " 1) Why Extend the STL" << endl;
		cout << " 2) Writing a STL Algorithm" << endl;
		cout << " 3) Writing a STL Container" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			subParagraph_17_3_1();
			break;
		case 2:
			subParagraph_17_3_2();
			break;
		case 3:
			subParagraph_17_3_3();
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
