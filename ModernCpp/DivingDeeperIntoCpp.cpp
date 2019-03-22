#include "pch.h"
//#include "pch.h"
//
//#include "GetMenuChoice.cpp"
//
////****************************************************************************
////*                     divingDeeperIntoCpp
////****************************************************************************
//// function must be inline
//inline void divingDeeperIntoCpp() {
//	OutputDebugString(L"divingDeeperIntoCpp()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Diving deeper into C++" << endl;
//		cout << "======================" << endl;
//		cout << " 1) Pointers and Dynamic memory" << endl;
//		cout << " 2) Strings in C++" << endl;
//		cout << " 3) References" << endl;
//		cout << " 4) Exceptions" << endl;
//		cout << " 5) The many uses of const" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			cout << "Pointers and Dynamic memory" << endl;
//			cout << "===========================" << endl;
//
//			cout << "a) stack" << endl;
//			cout << "b) heap" << endl;
//
//			break;
//		case 2:
//			cout << "Strings in C++" << endl;
//			cout << "==============" << endl;
//
//			cout << "a) C string: char* pStr = \"Hello World\"" << endl;
//			cout << "b) C++ string: string str = \"Hello World\"" << endl;
//
//			break;
//		case 3:
//			cout << "References" << endl;
//			cout << "==========" << endl;
//			break;
//		case 4:
//			cout << "Exceptions" << endl;
//			cout << "==========" << endl;
//			break;
//		case 5:
//			cout << "The many uses of const" << endl;
//			cout << "======================" << endl;
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