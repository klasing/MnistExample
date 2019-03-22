#include "pch.h"

#include "Paragraph_3_1.cpp"
#include "Paragraph_3_2.cpp"
#include "Paragraph_3_3.cpp"
#include "Paragraph_3_4.cpp"
#include "Paragraph_3_5.cpp"
#include "Paragraph_3_6.cpp"

inline void chapter3() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 3, Designing with Objects" << endl;
		cout << "=================================" << endl;
		cout << " 1) Am I Thinking Procedurally?" << endl;
		cout << " 2) The Object-Oriented Philosophy" << endl;
		cout << " 3) Living in a World of Objects" << endl;
		cout << " 4) Object Relationships" << endl;
		cout << " 5) Abstraction" << endl;
		cout << " 6) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_3_1();
			break;
		case 2:
			paragraph_3_2();
			break;
		case 3:
			paragraph_3_3();
			break;
		case 4:
			paragraph_3_4();
			break;
		case 5:
			paragraph_3_5();
			break;
		case 6:
			paragraph_3_6();
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
////*                     chapter3
////****************************************************************************
//// function must be inline
//inline void chapter3() {
//	OutputDebugString(L"chapter3()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Chapter 3: " << endl;
//		cout << "==============" << endl;
//		cout << " 1) Am I thinking procedurally?" << endl;
//		cout << " 2) The Object-Oriented philosophy" << endl;
//		cout << " 3) Living in a world of Objects" << endl;
//		cout << " 4) Object relationships" << endl;
//		cout << " 5) Abstraction" << endl;
//		cout << " 6) Summary" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			cout << "Am I thinking procedurally?" << endl;
//			cout << "===========================" << endl;
//
//			break;
//		case 2:
//			cout << "The Object-Oriented philosophy" << endl;
//			cout << "==============================" << endl;
//
//			cout << "  Classes" << endl;
//			cout << "  Components" << endl;
//			cout << "  Properties" << endl;
//			cout << "  Behaviors" << endl;
//			cout << "  Bringing it all together" << endl;
//
//			break;
//		case 3:
//			cout << "Living in a world of Objects" << endl;
//			cout << "============================" << endl;
//
//			cout << "  Overobjectification" << endl;
//			cout << "  Overly general objects" << endl;
//
//			break;
//		case 4:
//			cout << "Object relationships" << endl;
//			cout << "====================" << endl;
//
//			cout << "  The Has-A relationship" << endl;
//			cout << "  The Is-A relationship" << endl;
//			cout << "  The fine line between Has-A and Is-A" << endl;
//			cout << "  The Not-A relationship" << endl;
//			cout << "  Hierarchies" << endl;
//			cout << "  Multiple inheritance" << endl;
//			cout << "  Mix-in classes" << endl;
//
//			break;
//		case 5:
//			cout << "Abstraction" << endl;
//			cout << "===========" << endl;
//
//			cout << "  Interface versus Implementation" << endl;
//			cout << "  Deciding on an Exposed Interface" << endl;
//			cout << "  Designing a successful abstraction" << endl;
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