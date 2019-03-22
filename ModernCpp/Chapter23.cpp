#include "pch.h"

#include "Paragraph_23_1.cpp"
#include "Paragraph_23_2.cpp"
#include "Paragraph_23_3.cpp"
#include "Paragraph_23_4.cpp"
#include "Paragraph_23_5.cpp"
#include "Paragraph_23_6.cpp"

inline void chapter23() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 23, Maximizing Software Engineering Methods" << endl;
		cout << "===================================================" << endl;
		cout << " 1) The Need for Process" << endl;
		cout << " 2) Software Life Cycle Management" << endl;
		cout << " 3) Software Engineering Methodologies" << endl;
		cout << " 4) Building Your Own Process and Methodology" << endl;
		cout << " 5) Source Code Control" << endl;
		cout << " 6) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_23_1();
			break;
		case 2:
			paragraph_23_2();
			break;
		case 3:
			paragraph_23_3();
			break;
		case 4:
			paragraph_23_4();
			break;
		case 5:
			paragraph_23_5();
			break;
		case 6:
			paragraph_23_6();
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
//
////****************************************************************************
////*                     chapter23
////****************************************************************************
//// function must be inline
//inline void chapter23() {
//	OutputDebugString(L"chapter23()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Maximizing software engineering methods" << endl;
//		cout << "=======================================" << endl;
//		cout << " 1) The need for process" << endl;
//		cout << " 2) Software life cycle models" << endl;
//		cout << " 3) Software engineering methodologies" << endl;
//		cout << " 4) Building your own process and methodology" << endl;
//		cout << " 5) Source code control" << endl;
//		cout << " 6) Summary" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			cout << "The need for process" << endl;
//			cout << "====================" << endl;
//
//			break;
//		case 2:
//			cout << "Software life cycle models" << endl;
//			cout << "==========================" << endl;
//
//			break;
//		case 3:
//			cout << "Software engineering methodologies" << endl;
//			cout << "==================================" << endl;
//
//			break;
//		case 4:
//			cout << "Building your own process and methodology" << endl;
//			cout << "=========================================" << endl;
//
//			break;
//		case 5:
//			cout << "Source code control" << endl;
//			cout << "===================" << endl;
//
//			break;
//		case 6:
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