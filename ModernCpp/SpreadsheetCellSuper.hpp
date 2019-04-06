#pragma once

#include <string>

using namespace std;

class SpreadsheetCellSuper {
public:
	SpreadsheetCellSuper() {}
	virtual ~SpreadsheetCellSuper() {}
	virtual void set(const string& inString) = 0;
	virtual string getString() const = 0;
};