#include "pch.h"

#include "Paragraph_20_1.cpp"
#include "Paragraph_20_2.cpp"
#include "Paragraph_20_3.cpp"
#include "Paragraph_20_4.cpp"
#include "Paragraph_20_5.cpp"
#include "Paragraph_20_6.cpp"
#include "Paragraph_20_7.cpp"
#include "Paragraph_20_8.cpp"

inline void chapter20() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 20, Advanced Templates" << endl;
		cout << "==============================" << endl;
		cout << " 1) More about Template Parameters" << endl;
		cout << " 2) Template Class Partial Specialization" << endl;
		cout << " 3) Emulating Function Partial Specialization with Overloading" << endl;
		cout << " 4) Template Recursion" << endl;
		cout << " 5) Type Inference" << endl;
		cout << " 6) Variadic Templates" << endl;
		cout << " 7) Metaprogramming" << endl;
		cout << " 8) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_20_1();
			break;
		case 2:
			paragraph_20_2();
			break;
		case 3:
			paragraph_20_3();
			break;
		case 4:
			paragraph_20_4();
			break;
		case 5:
			paragraph_20_5();
			break;
		case 6:
			paragraph_20_6();
			break;
		case 7:
			paragraph_20_7();
			break;
		case 8:
			paragraph_20_8();
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
