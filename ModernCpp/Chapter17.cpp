#include "pch.h"

#include "Paragraph_17_1.cpp"
#include "Paragraph_17_2.cpp"
#include "Paragraph_17_3.cpp"
#include "Paragraph_17_4.cpp"

inline void chapter17() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 17, Customizing and Extending the STL" << endl;
		cout << "=============================================" << endl;
		cout << " 1) Allocators" << endl;
		cout << " 2) Iterator Adapters" << endl;
		cout << " 3) Extending the STL" << endl;
		cout << " 4) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_17_1();
			break;
		case 2:
			paragraph_17_2();
			break;
		case 3:
			paragraph_17_3();
			break;
		case 4:
			paragraph_17_4();
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
