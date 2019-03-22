#include "pch.h"

#include "Paragraph_28_1.cpp"
#include "Paragraph_28_2.cpp"
#include "Paragraph_28_3.cpp"
#include "Paragraph_28_4.cpp"

inline void chapter28() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 28, Incorporating Design Techniques and Frameworks" << endl;
		cout << "==========================================================" << endl;
		cout << " 1) \"I Can Never Remember How To...\"" << endl;
		cout << " 2) There Must Be a Better Way" << endl;
		cout << " 3) Object-Oriented Frameworks" << endl;
		cout << " 4) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_28_1();
			break;
		case 2:
			paragraph_28_2();
			break;
		case 3:
			paragraph_28_3();
			break;
		case 4:
			paragraph_28_4();
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
