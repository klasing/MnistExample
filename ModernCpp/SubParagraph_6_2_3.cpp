#include "pch.h"

#include "SpreadsheetCell_6_2_1.hpp"

inline void subParagraph_6_2_3() {
	cout << "Using Objects" << endl;
	cout << "-------------" << endl;

	cout << "Objects on the Stack" << endl;
	SpreadsheetCell_6_2_1 myCell, anotherCell;
	myCell.setValue(6);
	anotherCell.setString("3.2");
	cout << "-> cell 1: " << myCell.getValue() << endl;
	cout << "-> cell 2: " << anotherCell.getValue() << endl;

	cout << "Objects on the Heap" << endl;
	// old style
	SpreadsheetCell_6_2_1* myCellp = new SpreadsheetCell_6_2_1();
	myCellp->setValue(3.7);
	cout << "-> cell 1: " << myCellp->getValue() << " "
		<< myCellp->getString() << endl;
	delete myCellp;
	myCellp = nullptr;
	// highly recommended to use smart pointers, nowadays
	shared_ptr<SpreadsheetCell_6_2_1> myCellsp(new SpreadsheetCell_6_2_1());
	myCellsp->setValue(3.7);
	cout << "-> cell 1: " << myCellsp->getValue() << " "
		<< myCellsp->getString() << endl;
}
