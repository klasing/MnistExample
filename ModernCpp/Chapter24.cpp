#include "pch.h"

#include "Paragraph_24_1.cpp"
#include "Paragraph_24_2.cpp"
#include "Paragraph_24_3.cpp"
#include "Paragraph_24_4.cpp"
#include "Paragraph_24_5.cpp"

inline void chapter24() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 24, Writing Efficient C++" << endl;
		cout << "=================================" << endl;
		cout << " 1) Overview of Performance and Efficiency" << endl;
		cout << " 2) Language-Level Efficiency" << endl;
		cout << " 3) Design-Level Efficiency" << endl;
		cout << " 4) Profiling" << endl;
		cout << " 5) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_24_1();
			break;
		case 2:
			paragraph_24_2();
			break;
		case 3:
			paragraph_24_3();
			break;
		case 4:
			paragraph_24_4();
			break;
		case 5:
			paragraph_24_5();
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
//#include "DesignLevelEfficiency.cpp"
//
////****************************************************************************
////*                     chapter24
////****************************************************************************
//// function must be inline
//inline void chapter24() {
//	OutputDebugString(L"chapter24()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Writing efficient C++" << endl;
//		cout << "=====================" << endl;
//		cout << " 1) Overview of Performance and Efficiency" << endl;
//		cout << " 2) Language-level Efficiency" << endl;
//		cout << " 3) Design-level Efficiency " << endl;
//		cout << " 4) Profiling" << endl;
//		cout << " 5) Summary" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			cout << "Overview of Performance and Efficiency" << endl;
//			cout << "======================================" << endl;
//
//			break;
//		case 2:
//			cout << "Language-level Efficiency" << endl;
//			cout << "=========================" << endl;
//
//			break;
//		case 3:
//			cout << "Design-level Efficiency" << endl;
//			cout << "=======================" << endl;
//
//			designLevelEfficiency();
//
//			break;
//		case 4:
//			cout << "Profiling" << endl;
//			cout << "=========" << endl;
//
//			break;
//		case 5:
//			cout << "Summary" << endl;
//			cout << "=======" << endl;
//
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