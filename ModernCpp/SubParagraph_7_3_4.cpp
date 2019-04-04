#include "pch.h"

#include "SpreadsheetApplication.hpp"
#include "SpreadsheetImpl.hpp"

inline void subParagraph_7_3_4() {
	cout << "Default Parameters" << endl;
	cout << "------------------" << endl;

	SpreadsheetApplication theApp;
	SpreadsheetImpl s1(theApp);
	SpreadsheetImpl s2(theApp, 5);
	SpreadsheetImpl s3(theApp, 5, 6);
}