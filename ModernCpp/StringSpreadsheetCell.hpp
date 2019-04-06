#pragma once

#include <string>
#include "SpreadsheetCellSuper.hpp"
#include "DoubleSpreadsheetCell.hpp"

using namespace std;

class StringSpreadsheetCell : public SpreadsheetCellSuper {
public:
	StringSpreadsheetCell() : mValue("#NOVALUE") {}
	StringSpreadsheetCell(const DoubleSpreadsheetCell& inDoubleCell) {}
	virtual void set(const string& inString) {
		mValue = inString;
	}
	virtual string getString() const {
		return mValue;
	}
protected:
	string mValue;
};