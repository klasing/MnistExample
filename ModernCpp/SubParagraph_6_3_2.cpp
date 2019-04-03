#include "pch.h"

#include "SpreadsheetCell.hpp"

inline int main_6_3_2_a() {
	SpreadsheetCell myCell(5);
	if (myCell.getValue() == 5) {
		SpreadsheetCell anotherCell(6);
		// anotherCell is destroyed as this block ends.
	}
	cout << "-> myCell: " << myCell.getValue() << endl;

	SpreadsheetCell myCell2(4);
	// myCell2 constructed before anotherCell2
	SpreadsheetCell anotherCell2(5);
	// anotherCell2 destroyed before myCell2

	// myCell is destroyed as this block ends.
	return 0;
}

inline int main_6_3_2_b() {
	SpreadsheetCell* cellPtr1 = new SpreadsheetCell(5);
	SpreadsheetCell* cellPtr2 = new SpreadsheetCell(6);
	cout << "-> cellPtr1: " << cellPtr1->getValue() << endl;
	// Destroys cellPtr1
	delete cellPtr1;
	cellPtr1 = nullptr;
	// cellPtr2 is NOT destroyed because delete was not called on it.
	return 0;
}

inline void subParagraph_6_3_2() {
	cout << "Object Destruction" << endl;
	cout << "------------------" << endl;

	main_6_3_2_a();
	main_6_3_2_b();
}