#include "pch.h"

#include "SpreadsheetCell_6_2_1.hpp"
#include "PointSequence.hpp"

inline void subParagraph_6_3_1() {
	cout << "Object Creation" << endl;
	cout << "---------------" << endl;

	cout << "a) Writing Constructors" << endl;
	cout << "b) Using Constructors" << endl;
	cout << "   b.1) Constructors on the Stack" << endl;
	SpreadsheetCell_6_2_1 myCell_b1(5), anotherCell_b1(4);
	cout << "-> cell 1: " << myCell_b1.getValue() << endl;
	cout << "-> cell 2: " << anotherCell_b1.getValue() << endl;
	cout << "   b.2) Constructors on the Heap" << endl;
	SpreadsheetCell_6_2_1 *myCellp_b2 = new SpreadsheetCell_6_2_1(5);
	SpreadsheetCell_6_2_1 *anotherCellp_b2 = nullptr;
	anotherCellp_b2 = new SpreadsheetCell_6_2_1(4);
	// ... do something with the cells
	delete myCellp_b2;
	myCellp_b2 = nullptr;
	delete anotherCellp_b2;
	anotherCellp_b2 = nullptr;
	cout << "c) Providing Multiple Constructors" << endl;
	// Uses string-arg ctor
	SpreadsheetCell_6_2_1 aTirdCell_c("test");
	// Uses double-arg ctor
	SpreadsheetCell_6_2_1 aFourthCell_c(4.4);
	// string-arg ctor
	SpreadsheetCell_6_2_1* aTirdCellp_c = new SpreadsheetCell_6_2_1("4.4");
	cout << "-> aTirdCell: " << aTirdCell_c.getValue() << endl;
	cout << "-> aFourthCell: " << aFourthCell_c.getValue() << endl;
	cout << "-> aTirdCellp: " << aTirdCellp_c->getValue() << endl;
	delete aTirdCellp_c;
	aTirdCellp_c = nullptr;
	cout << "d) Default Constructors" << endl;
	cout << "   d.1) When You Need a Default Constructor" << endl;
	cout << "   d.2) How To Write a Default Constructor" << endl;
	SpreadsheetCell_6_2_1 myCell_d2;
	myCell_d2.setValue(6);
	cout << "-> cell1: " << myCell_d2.getValue() << endl;
	// Note the function call syntax
	SpreadsheetCell_6_2_1* myCellp_d2 = new SpreadsheetCell_6_2_1();
	cout << "   d.3) Compiler-Generated Default Constructor" << endl;
	cout << "   d.4) Explicitly Defaulted Constructors (C++11)" << endl;
	cout << "   d.5) Explicitly Deleted Constructors (C++11)" << endl;
	cout << "e) Constructor Initializers" << endl;
	cout << "f) Copy Constructors" << endl;
	cout << "   f.1) When the Copy Constructor Is Called" << endl;
	cout << "   f.2) Calling the Copy Constructor Explicitly" << endl;
	SpreadsheetCell_6_2_1 myCell2_f2(4);
	// myCell3 has the same values as myCell2
	SpreadsheetCell_6_2_1 myCell3_f2(myCell2_f2);
	cout << "   f.3) Passing Objects by Reference" << endl;
	cout << "   f.4) Explicitly Defaulted and Deleted Copy Constructor (C++11)" << endl;
	cout << "g) Initializer-List Constructors (C++11)" << endl;
	//PointSequence p1 = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	// can also be written as:
	PointSequence p1{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	p1.dumpPoints();
	try {
		PointSequence p2 = { 1.0, 2.0, 3.0 };
	}
	catch (const invalid_argument& e) {
		cout << "-> " << e.what() << endl;
	}
	cout << "h) In-Class Member Initializers (C++11)" << endl;
	cout << "i) Delegating Constructors (C++11)" << endl;
	cout << "j) Summary of Compiler-Generated Constructors" << endl;
}
