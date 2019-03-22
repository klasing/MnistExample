#include "pch.h"

#include "Chapter23.cpp"
#include "Chapter24.cpp"
#include "Chapter25.cpp"
#include "Chapter26.cpp"
#include "Chapter27.cpp"
#include "Chapter28.cpp"
#include "Chapter29.cpp"

inline void part4() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Part IV, C++ Software Engineering" << endl;
		cout << "=================================" << endl;
		cout << " 1) Chapter 23, Maximizing Software Engineering Methods" << endl;
		cout << " 2) Chapter 24, Writing Efficient C++" << endl;
		cout << " 3) Chapter 25, Developing Cross-Platform and Cross-Language Applications" << endl;
		cout << " 4) Chapter 26, Becoming Adept at Testing" << endl;
		cout << " 5) Chapter 27, Conquering Debugging" << endl;
		cout << " 6) Chapter 28, Incorporating Design Techniques and Frameworks" << endl;
		cout << " 7) Chapter 29, Applying Design Patterns" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			chapter23();
			break;
		case 2:
			chapter24();
			break;
		case 3:
			chapter25();
			break;
		case 4:
			chapter26();
			break;
		case 5:
			chapter27();
			break;
		case 6:
			chapter28();
			break;
		case 7:
			chapter29();
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
//#include "Chapter23.cpp"
//#include "Chapter24.cpp"
////#include "Chapter25.cpp"
//
////****************************************************************************
////*                     part4
////****************************************************************************
//// function must be inline
//inline void part4() {
//	OutputDebugString(L"part4()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Part IV, C++ Software Engineering" << endl;
//		cout << "==================================" << endl;
//		cout << " 1) Chapter 23, Maximizing software engineering methods" << endl;
//		cout << " 2) Chapter 24, Writing efficient C++" << endl;
//		cout << " 3) Chapter 25, Developing Cross-platform and Cross-language applications" << endl;
//		cout << " 4) Chapter 26, Becoming adept at testing" << endl;
//		cout << " 5) Chapter 27, Conquering debugging" << endl;
//		cout << " 6) Chapter 28, Incorporating design techniques and frameworks" << endl;
//		cout << " 7) Chapter 29, Applying design patterns" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			chapter23();
//			break;
//		case 2:
//			chapter24();
//			break;
//		case 3:
//			//chapter25();
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