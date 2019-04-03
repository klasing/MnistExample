#include "pch.h"

#include "SpreadsheetCell.hpp"

inline void subParagraph_7_7_2() {
	cout << "Overloading Arithmetic Operators" << endl;
	cout << "--------------------------------" << endl;

	cout << "a) Overloading the Arithmetic Shorthand Operators" << endl;
	SpreadsheetCell myCell(4), aThirdCell(2);
	aThirdCell -= myCell;
	aThirdCell += 5.4;
	// cannot, which is a good thing!
	//5.4 += aThirdCell;
}