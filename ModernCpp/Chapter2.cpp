#include "pch.h"

#include "Paragraph_2_1.cpp"
#include "Paragraph_2_2.cpp"
#include "Paragraph_2_3.cpp"
#include "Paragraph_2_4.cpp"
#include "Paragraph_2_5.cpp"
#include "Paragraph_2_6.cpp"
#include "Paragraph_2_7.cpp"
#include "Paragraph_2_8.cpp"

inline void chapter2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 2, Designing Professional C++ Programs" << endl;
		cout << "==============================================" << endl;
		cout << " 1) What is Programming Design?" << endl;
		cout << " 2) The Importance of Programming Design" << endl;
		cout << " 3) What's Different about C++ Design?" << endl;
		cout << " 4) Two Rules for C++ Design" << endl;
		cout << " 5) Reusing Code" << endl;
		cout << " 6) Designing with Patterns and Techniques" << endl;
		cout << " 7) Designing a Chess Program" << endl;
		cout << " 8) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			paragraph_2_1();
			break;
		case 2:
			paragraph_2_2();
			break;
		case 3:
			paragraph_2_3();
			break;
		case 4:
			paragraph_2_4();
			break;
		case 5:
			paragraph_2_5();
			break;
		case 6:
			paragraph_2_6();
			break;
		case 7:
			paragraph_2_7();
			break;
		case 8:
			paragraph_2_8();
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
////*                     chapter2
////****************************************************************************
//// function must be inline
//inline void chapter2() {
//	OutputDebugString(L"chapter2()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Chapter 2: Designing Professional C++ programs" << endl;
//		cout << "==============================================" << endl;
//		cout << " 1) What is Programming design?" << endl;
//		cout << " 2) The importance of Programming design" << endl;
//		cout << " 3) What's different about C++ design" << endl;
//		cout << " 4) Two rules for C++ design" << endl;
//		cout << " 5) Reusing code" << endl;
//		cout << " 6) Designing with Patterns and Techniques" << endl;
//		cout << " 7) Designing a Chess program" << endl;
//		cout << " 8) Summary" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			cout << "What is Programming design?" << endl;
//			cout << "===========================" << endl;
//
//			break;
//		case 2:
//			cout << "The importance of Programming design" << endl;
//			cout << "====================================" << endl;
//
//			break;
//		case 3:
//			cout << "What's different about C++ design" << endl;
//			cout << "=================================" << endl;
//
//
//			break;
//		case 4:
//			cout << "Two rules for C++ design" << endl;
//			cout << "========================" << endl;
//
//			cout << "Abstraction" << endl;
//			cout << "Reuse" << endl;
//
//			break;
//		case 5:
//			cout << "Reusing code" << endl;
//			cout << "============" << endl;
//
//			cout << "A note on terminology" << endl;
//			cout << "* Stand-alone functions or classes" << endl;
//			cout << "* Libraries" << endl;
//			cout << "* Frameworks" << endl;
//			cout << "Deciding whether or not to reuse code" << endl;
//			cout << "  Advantages to reusing code" << endl;
//			cout << "  Disadvantages to reusing code" << endl;
//			cout << "  Putting it together to make a decision" << endl;
//			cout << "Strategies for reusing code" << endl;
//			cout << "  Understand the Capabilities and Limitations" << endl;
//			cout << "  Understand the performance" << endl;
//			cout << "  Understand platform limitations" << endl;
//			cout << "  Understand Licensing and Support" << endl;
//			cout << "  Know where to find help" << endl;
//			cout << "  Prototype" << endl;
//			cout << "Bundling Third-Party applications" << endl;
//			cout << "Open-Source libraries" << endl;
//			cout << "  The Open-Source movements" << endl;
//			cout << "  Finding and using Open-Source libraries" << endl;
//			cout << "  * www.opensource.org" << endl;
//			cout << "  * www.gnu.org" << endl;
//			cout << "  * www.sourceforge.net" << endl;
//			cout << "  Guidelines for using Open-Source code" << endl;
//			cout << "The C++ Standard Library" << endl;
//			cout << "  C Standard Library" << endl;
//			cout << "  Deciding whether or not to use the STL" << endl;
//
//			break;
//		case 6:
//			cout << "Designing with Patterns and Techniques" << endl;
//			cout << "======================================" << endl;
//
//			break;
//		case 7:
//			cout << "Designing a Chess program" << endl;
//			cout << "=========================" << endl;
//
//			cout << "Requirement steps" << endl;
//			cout << endl;
//			cout << "Design steps" << endl;
//			cout << "a) Divide the program into Subsystems" << endl;
//			cout << "b) Choose threading models" << endl;
//			cout << "c) Specify class hierarchies for each subsystem" << endl;
//			cout << "d) Specify classis, data structures, algorithms and patterns for each subsystem" << endl;
//			cout << "e) Specify error handling for each subsystem" << endl;
//			cout << "" << endl;
//
//			break;
//		case 8:
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