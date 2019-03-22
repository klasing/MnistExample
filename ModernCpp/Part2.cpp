#include "pch.h"

#include "Chapter6.cpp"
#include "Chapter7.cpp"
#include "Chapter8.cpp"
#include "Chapter9.cpp"
#include "Chapter10.cpp"
#include "Chapter11.cpp"
#include "Chapter12.cpp"
#include "Chapter13.cpp"
#include "Chapter14.cpp"
#include "Chapter15.cpp"
#include "Chapter16.cpp"
#include "Chapter17.cpp"

inline void part2() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Part II, C++ Coding the Professional Way" << endl;
		cout << "========================================" << endl;
		cout << " 1) Chapter 6, Gaining Proficiency with Classes and Objects" << endl;
		cout << " 2) Chapter 7, Mastering Classes and Objects" << endl;
		cout << " 3) Chapter 8, Discovering Inheritance Techniques" << endl;
		cout << " 4) Chapter 9, Understanding C++ Quirks and Oddities" << endl;
		cout << " 5) Chapter 10, Handling Errors" << endl;
		cout << " 6) Chapter 11, Delving into the Standard Library" << endl;
		cout << " 7) Chapter 12, Understanding Containers and Iterators" << endl;
		cout << " 8) Chapter 13, Mastering STL Algorithms" << endl;
		cout << " 9) Chapter 14, Using Strings and Regular Expressions" << endl;
		cout << "10) Chapter 15, Demystifying C++ I/O" << endl;
		cout << "11) Chapter 16, Additional Library Utilities" << endl;
		cout << "12) Chapter 17, Customizing and Extending the STL" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			chapter6();
			break;
		case 2:
			chapter7();
			break;
		case 3:
			chapter8();
			break;
		case 4:
			chapter9();
			break;
		case 5:
			chapter10();
			break;
		case 6:
			chapter11();
			break;
		case 7:
			chapter12();
			break;
		case 8:
			chapter13();
			break;
		case 9:
			chapter14();
			break;
		case 10:
			chapter15();
			break;
		case 11:
			chapter16();
			break;
		case 12:
			chapter17();
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
//#include "Chapter6.cpp"
//#include "Chapter13.cpp"
//#include "Chapter16.cpp"
//
////****************************************************************************
////*                     part2
////****************************************************************************
//// function must be inline
//inline void part2() {
//	OutputDebugString(L"part2()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Part II,  C++ Coding the Professional Way" << endl;
//		cout << "=========================================" << endl;
//		cout << " 1) Chapter 6, Gaining proficiency with Classes and Objects" << endl;
//		cout << " 2) Chapter 7, Mastering Classes and Objects" << endl;
//		cout << " 3) Chapter 8, Discovering inheritance techniques" << endl;
//		cout << " 4) Chapter 9, Understanding C++ quirks and oddities" << endl;
//		cout << " 5) Chapter 10, Handling errors" << endl;
//		cout << " 6) Chapter 11, Delving into the Standard Library" << endl;
//		cout << " 7) Chapter 12, Understanding Containers and Iterators" << endl;
//		cout << " 8) Chapter 13, Mastering STL algorithms" << endl;
//		cout << " 9) Chapter 14, Using strings and regular expressions" << endl;
//		cout << "10) Chapter 15, Demystifying C++ I/O" << endl;
//		cout << "11) Chapter 16, Additional Library utilities" << endl;
//		cout << "12) Chapter 17, Customizing and extending the STL" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			chapter6();
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
//		case 7:
//			break;
//		case 8:
//			chapter13();
//			break;
//		case 9:
//			break;
//		case 10:
//			break;
//		case 11:
//			chapter16();
//			break;
//		case 12:
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