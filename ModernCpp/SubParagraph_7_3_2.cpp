#include "pch.h"

#include "SpreadsheetCell.hpp"

inline void subParagraph_7_3_2() {
	cout << "const Methods" << endl;
	cout << "-------------" << endl;

	SpreadsheetCell myCell(5);
	// OK
	cout << "-> " << myCell.getValue() << endl;
	// OK
	myCell.setString("6");
	const SpreadsheetCell& anotherCell = myCell;
	// OK
	cout << "-> " << anotherCell.getValue() << endl;
	// Compilation Error
	//anotherCell.setString("6");

	cout << "a) mutable Data Members" << endl;
}