#include "pch.h"

#include "SpreadsheetCell.hpp"

inline void subParagraph_21_3_6() {
	cout << "Pointers to Methods and Members" << endl;
	cout << "-------------------------------" << endl;

	SpreadsheetCell myCell(123);
	//double (SpreadsheetCell::*methodPtr) () const = &SpreadsheetCell::getValue;
	// or by using a typedef	
	typedef double (SpreadsheetCell::*PtrToGet) () const;
	PtrToGet methodPtr = &SpreadsheetCell::getValue;
	cout << "-> " << (myCell.*methodPtr)() << endl;
}