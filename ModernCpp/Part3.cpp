#include "pch.h"

#include "Chapter18.cpp"
#include "Chapter19.cpp"
#include "Chapter20.cpp"
#include "Chapter21.cpp"
#include "Chapter22.cpp"

inline void part3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Part III, Mastering Advanced Features of C++" << endl;
		cout << "============================================" << endl;
		cout << " 1) Chapter 18, Overloading C++ Operators" << endl;
		cout << " 2) Chapter 19, Writing Generic Code with Templates" << endl;
		cout << " 3) Chapter 20, Advanced Templates" << endl;
		cout << " 4) Chapter 21, Effective Memory Management" << endl;
		cout << " 5) Chapter 22, Multithreaded Programming with C++" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			chapter18();
			break;
		case 2:
			chapter19();
			break;
		case 3:
			chapter20();
			break;
		case 4:
			chapter21();
			break;
		case 5:
			chapter22();
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
//#include "Chapter22.cpp"
//
////****************************************************************************
////*                     part3
////****************************************************************************
//// function must be inline
//inline void part3() {
//	OutputDebugString(L"part3()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Part III,  Mastering Advanced Features of C++" << endl;
//		cout << "=============================================" << endl;
//		cout << " 1) Chapter 18, Overlaoding C++ operators" << endl;
//		cout << " 2) Chapter 19, Writing generic code with templates" << endl;
//		cout << " 3) Chapter 20, Advanced templates" << endl;
//		cout << " 4) Chapter 21, Effective memory management" << endl;
//		cout << " 5) Chapter 22, Multithreaded programming with C++" << endl;
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
//			break;
//		case 4:
//			break;
//		case 5:
//			chapter22();
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