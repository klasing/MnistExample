#pragma once

#include <string>
#include "SpreadsheetCellSuper.hpp"

using namespace std;

class DoubleSpreadsheetCell : public SpreadsheetCellSuper {
public:
	// instead of initializing mValue to -1
	// std::numeric_limits<double>::quiet_NaN()
	// could be used
	DoubleSpreadsheetCell() : mValue(-1) {}
	virtual void set(double inDouble) {
		mValue = inDouble;
	}
	virtual void set(const string& inString) {
		mValue = stringToDouble(inString);
	}
	virtual string getString() const {
		return doubleToString(mValue);
	}
protected:
	static string doubleToString(double inValue) {
		return "?";
	}
	static double stringToDouble(const string& inValue) {
		return 0;
	}
	double mValue;
};