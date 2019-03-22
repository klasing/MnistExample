#include "pch.h"

#include "Paragraph_13_1.cpp"
#include "Paragraph_13_2.cpp"
#include "Paragraph_13_3.cpp"
#include "Paragraph_13_4.cpp"
#include "Paragraph_13_5.cpp"
#include "Paragraph_13_6.cpp"

inline void chapter13() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 13, Mastering STL Algorithms" << endl;
		cout << "====================================" << endl;
		cout << " 1) Overview of Algorithms" << endl;
		cout << " 2) Lambda Expressions" << endl;
		cout << " 3) Function Objects" << endl;
		cout << " 4) Algorithm Details" << endl;
		cout << " 5) Algorithm Example: Auditing Voter Registrations" << endl;
		cout << " 6) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_13_1();
			break;
		case 2:
			paragraph_13_2();
			break;
		case 3:
			paragraph_13_3();
			break;
		case 4:
			paragraph_13_4();
			break;
		case 5:
			paragraph_13_5();
			break;
		case 6:
			paragraph_13_6();
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
//#include "OverviewOfAlgorithms.cpp"
//
////****************************************************************************
////*                     chapter13
////****************************************************************************
//// function must be inline
//inline void chapter13() {
//	OutputDebugString(L"chapter13()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Mastering STL algorithms" << endl;
//		cout << "========================" << endl;
//		cout << " 1) Overview of Algorithms" << endl;
//		cout << " 2) Lambda expressions" << endl;
//		cout << " 3) Function Objects" << endl;
//		cout << " 4) Algorithm details" << endl;
//		cout << " 5) Algorithms example: Auditing voter registration" << endl;
//		cout << " 6) Summary" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			overviewOfAlgorithms();
//			break;
//		case 2:
//			break;
//		case 3:
//			break;
//		case 4:
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