#include "pch.h"

#include "Paragraph_19_1.cpp"
#include "Paragraph_19_2.cpp"
#include "Paragraph_19_3.cpp"
#include "Paragraph_19_4.cpp"

inline void chapter19() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 19, Writing Generic Code with Templates" << endl;
		cout << "===============================================" << endl;
		cout << " 1) Overview of Templates" << endl;
		cout << " 2) Class Templates" << endl;
		cout << " 3) Function Templates" << endl;
		cout << " 4) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_19_1();
			break;
		case 2:
			paragraph_19_2();
			break;
		case 3:
			paragraph_19_3();
			break;
		case 4:
			paragraph_19_4();
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
