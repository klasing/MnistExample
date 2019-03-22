#include "pch.h"

#include "Paragraph_5_1.cpp"
#include "Paragraph_5_2.cpp"
#include "Paragraph_5_3.cpp"
#include "Paragraph_5_4.cpp"
#include "Paragraph_5_5.cpp"
#include "Paragraph_5_6.cpp"
#include "Paragraph_5_7.cpp"
#include "Paragraph_5_8.cpp"

inline void chapter5() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 5, Coding with Style" << endl;
		cout << "============================" << endl;
		cout << " 1) The Importance of Looking Good" << endl;
		cout << " 2) Documenting Your Code" << endl;
		cout << " 3) Decomposition" << endl;
		cout << " 4) Naming" << endl;
		cout << " 5) Using Language Features with Style" << endl;
		cout << " 6) Formatting" << endl;
		cout << " 7) Stylistic Challenges" << endl;
		cout << " 8) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_5_1();
			break;
		case 2:
			paragraph_5_2();
			break;
		case 3:
			paragraph_5_3();
			break;
		case 4:
			paragraph_5_4();
			break;
		case 5:
			paragraph_5_5();
			break;
		case 6:
			paragraph_5_6();
			break;
		case 7:
			paragraph_5_7();
			break;
		case 8:
			paragraph_5_8();
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
