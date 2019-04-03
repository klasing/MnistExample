#include "pch.h"

#include "SpreadsheetApplication.hpp"
#include "Spreadsheet.hpp"

inline void subParagraph_7_3_4() {
	cout << "Default Parameters" << endl;
	cout << "------------------" << endl;

	SpreadsheetApplication theApp;
	Spreadsheet s1(theApp);
	Spreadsheet s2(theApp, 5);
	Spreadsheet s3(theApp, 5, 6);
}