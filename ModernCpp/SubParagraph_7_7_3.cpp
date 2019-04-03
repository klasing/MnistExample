#include "pch.h"

#include "SpreadsheetCell.hpp"

inline void subParagraph_7_7_3() {
	cout << "Overloading Comparison Operators" << endl;
	cout << "--------------------------------" << endl;

	SpreadsheetCell myCell(4), aThirdCell(2);
	if (myCell > aThirdCell || myCell < 10)
		cout << "-> " << myCell.getValue() << endl;
}