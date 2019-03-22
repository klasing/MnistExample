#include "pch.h"

//#include "Paragraph_6_1.cpp"
//#include "Paragraph_6_2.cpp"
//#include "Paragraph_6_3.cpp"
//#include "Paragraph_6_4.cpp"

inline void chapter6() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "Chapter 6, Gaining Proficiency with Classes and Objects" << endl;
		cout << "=======================================================" << endl;
		cout << " 1) Introducing the Spreadsheet Example" << endl;
		cout << " 2) Writing Classes" << endl;
		cout << " 3) Object Life Cycles" << endl;
		cout << " 4) Summary" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 1:
			//paragraph_6_1();
			break;
		case 2:
			//paragraph_6_2();
			break;
		case 3:
			//paragraph_6_3();
			break;
		case 4:
			//paragraph_6_4();
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
////*                     chapter6
////****************************************************************************
//// function must be inline
//inline void chapter6() {
//	OutputDebugString(L"chapter6()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Chapter 6: Gaining proficiency with Classes and Objects" << endl;
//		cout << "=======================================================" << endl;
//		cout << " 1) Introduccing to the spreadsheet example" << endl;
//		cout << " 2) Writing Classes" << endl;
//		cout << " 3) Object life  cycle" << endl;
//		cout << " 4) Summary" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1:
//			cout << "Introduccing to the spreadsheet example" << endl;
//			cout << "=======================================" << endl;
//
//			break;
//		case 2:
//			cout << "Writing Classes" << endl;
//			cout << "===============" << endl;
//
//			cout << "Class definitions" << endl;
//			cout << "  class SpreadsheetCell {" << endl;
//			cout << "  public:" << endl;
//			cout << "    void setValue(double inValue);" << endl;
//			cout << "    double getValue() const" << endl;
//			cout << "  protected:" << endl;
//			cout << "    double mValue;" << endl;
//			cout << "  };" << endl;
//			cout << "  A class declaration goes into a header file (.h)." << endl;
//			cout << endl;
//			cout << "  Methods and members" << endl;
//			cout << "    Methods:" << endl;
//			cout << "      void setValue(double inValue)" << endl;
//			cout << "      double getValue() const" << endl;
//			cout << "    Data member:" << endl;
//			cout << "      double mValue" << endl;
//			cout << "  Access control" << endl;
//			cout << "    Public (default, for struct and union)" << endl;
//			cout << "    Protected" << endl;
//			cout << "      A subclass can access a protected method or protected data member in its superclass" << endl;
//			cout << "    Private (default, for classes)" << endl;
//			cout << endl;
//			cout << "Defining methods" << endl;
//			cout << "  #include \"stdafx.h\"" << endl;
//			cout << "  #include \"spreadsheetcell.h\"" << endl;
//			cout << "  void SpreadsheetCell::setValue(double inValue) {" << endl;
//			cout << "    mValue = inValue;" << endl;
//			cout << "  }" << endl;
//			cout << "  double SpreadsheetCell::getValue() const {" << endl;
//			cout << "    return mValue;" << endl;
//			cout << "  }" << endl;
//			cout << "  stdafx.h is a precompiled header file, specific for the Microsoft Visual C++ IDE" << endl;
//			cout << "  :: is the scope resolution operator" << endl;
//			cout << "  A class definition goes into a source file (.cpp)." << endl;
//			cout << "  Accessing data members" << endl;
//			cout << "  Calling other methods" << endl;
//			cout << "  The this pointer" << endl;
//			cout << endl;
//			cout << "Using Objects" << endl;
//
//			break;
//		case 3:
//			cout << "Object life  cycle" << endl;
//			cout << "==================" << endl;
//
//			cout << "Object creation" << endl;
//			cout << "Object destruction" << endl;
//			cout << "Assigning to objects" << endl;
//			cout << "Distinguishing Copying from Assignment" << endl;
//
//			break;
//		case 4:
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