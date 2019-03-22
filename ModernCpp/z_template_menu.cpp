#include "pch.h"

//#include "SubParagraph_x_y_n.cpp"

inline void menu() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "..." << endl;
		cout << "===" << endl;
		cout << " 1) " << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//subParagraph_x_y_n();
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
////*                     chapterX
////****************************************************************************
//// function must be inline
//inline void chapterX() {
//	OutputDebugString(L"chapterX()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Chapter X: ..." << endl;
//		cout << "==============" << endl;
//		cout << " 1) " << endl;
//		cout << " 2) " << endl;
//		cout << " 3) " << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			cout << "..." << endl;
//			cout << "===" << endl;
//
//			break;
//		case 2:
//			cout << "..." << endl;
//			cout << "===" << endl;
//
//			break;
//		case 3:
//			cout << "..." << endl;
//			cout << "===" << endl;
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