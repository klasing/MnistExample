#include "pch.h"

#include "Chapter1.cpp"
#include "Chapter2.cpp"
#include "Chapter3.cpp"
#include "Chapter4.cpp"
#include "Chapter5.cpp"

inline void part1() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Part I, Introduction to Professional C++" << endl;
		cout << "========================================" << endl;
		cout << " 1) Chapter 1, A Crash Course in C++" << endl;
		cout << " 2) Chapter 2, Designing Professional C++ Programs" << endl;
		cout << " 3) Chapter 3, Designing with Objects" << endl;
		cout << " 4) Chapter 4, Designing for Reuse" << endl;
		cout << " 5) Chapter 5, Coding with Style" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			chapter1();
			break;
		case 2:
			chapter2();
			break;
		case 3:
			chapter3();
			break;
		case 4:
			chapter4();
			break;
		case 5:
			chapter5();
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
//#include "Chapter1.cpp"
//#include "Chapter2.cpp"
//#include "Chapter3.cpp"
//
////****************************************************************************
////*                     part1
////****************************************************************************
//// function must be inline
//inline void part1() {
//	OutputDebugString(L"part1()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Part I, Introduction to Professional C++" << endl;
//		cout << "========================================" << endl;
//		cout << " 1) Chapter 1: A Crash Course in C++" << endl;
//		cout << " 2) Chapter 2: Designing Professional C++ Programs" << endl;
//		cout << " 3) Chapter 3: Designing with Objects" << endl;
//		cout << " 4) Chapter 4: Designing for Reuse" << endl;
//		cout << " 5) Chapter 5: Coding with Style" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iChar = getchar() - 48;
//		// get rid of enter
//		getchar();
//
//		switch (iChar) {
//		case 1:
//			chapter1();
//			break;
//		case 2:
//			chapter2();
//			break;
//		case 3:
//			chapter3();
//			break;
//		case 4:
//			break;
//		case 5:
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