#include "pch.h"

#include "SpreadsheetCell.hpp"

inline void subParagraph_7_7_1() {
	cout << "Example: Implementing Addition for Spreadsheet Cells" << endl;
	cout << "----------------------------------------------------" << endl;

	cout << "a) First Attempt: The add Method" << endl;
	SpreadsheetCell myCell_a(4), anotherCell_a(5);
	SpreadsheetCell aThirdCell_a = myCell_a.add(anotherCell_a);
	cout << "b) Second Attempt: Overloaded operator+ as a Method" << endl;
	SpreadsheetCell myCell_b(4), anotherCell_b(5);
	SpreadsheetCell aThirdCell_b = myCell_b + anotherCell_b;
	cout << "   b.1) Implicit Conversions" << endl;
	SpreadsheetCell myCell_b1(4), aThirdCell_b1;
	string str = "hello";
	// can't be done anymore, after adding the keyword: explicit
	// in the SpreadsheetCell constructor with a string parameter
	// and the operator+ method with a double parameter
	//aThirdCell_b1 = myCell_b1 + str;
	aThirdCell_b1 = myCell_b1 + 5.6;
	aThirdCell_b1 = myCell_b1 + 4;
	cout << "c) Third Attempt: Global operator+" << endl;
	SpreadsheetCell myCell_c(4), aThirdCell_c;
	// Works fine.
	aThirdCell_c = myCell_c + 4;
	aThirdCell_c = myCell_c + 5.6;
	// FAILS TO COMPILE!
	//aThirdCell_c = 4 + myCell_c;
	//aThirdCell_c = 5.6 + myCell_c;
	// after introducing a global operator+ function
	// Works fine.
	aThirdCell_c = myCell_c + 4;
	aThirdCell_c = myCell_c + 5.6;
	// Works fine.
	aThirdCell_c = 4 + myCell_c;
	aThirdCell_c = 5.6 + myCell_c;
	// results in an itermediate statement:
	// aThirdCell_c = 10;
	aThirdCell_c = 4.5 + 5.5;
}