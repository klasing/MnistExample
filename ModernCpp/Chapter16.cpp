#include "pch.h"

#include "paragraph_16_1.cpp"
#include "paragraph_16_2.cpp"
#include "paragraph_16_3.cpp"
#include "paragraph_16_4.cpp"
#include "paragraph_16_5.cpp"
#include "paragraph_16_6.cpp"

inline void chapter16() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 16, Additional Library Utilities" << endl;
		cout << "========================================" << endl;
		cout << " 1) std::function" << endl;
		cout << " 2) Ratios" << endl;
		cout << " 3) The Chrono Library" << endl;
		cout << " 4) Random Number Generation" << endl;
		cout << " 5) Tuples" << endl;
		cout << " 6) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_16_1();
			break;
		case 2:
			paragraph_16_2();
			break;
		case 3:
			paragraph_16_3();
			break;
		case 4:
			paragraph_16_4();
			break;
		case 5:
			paragraph_16_5();
			break;
		case 6:
			paragraph_16_6();
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
//#include "pch.h"
//
//#include "GetMenuChoice.cpp"
//#include "ChronoLibrary.cpp"
//#include "RandomNumberGeneration.cpp"
//
////****************************************************************************
////*                     chapter16
////****************************************************************************
//// function must be inline
//inline void chapter16() {
//	OutputDebugString(L"chapter16()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Additional library utilities" << endl;
//		cout << "============================" << endl;
//		cout << " 1) std::function" << endl;
//		cout << " 2) Ratios" << endl;
//		cout << " 3) The Chrono library" << endl;
//		cout << " 4) Random number generation" << endl;
//		cout << " 5) Tuples" << endl;
//		cout << " 6) Summary" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			break;
//		case 2:
//			break;
//		case 3:
//			chronoLibrary();
//			break;
//		case 4:
//			randomNumberGeneration();
//			break;
//		case 5:
//			break;
//		case 6:
//			break;
//		case 0:
//			// the user wants to terminate the program
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			cout << "The entered number is not recognized, please try again." << endl;
//		} // eof switch
//		cout << endl;
//	}
//}