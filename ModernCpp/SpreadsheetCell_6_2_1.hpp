#pragma once

#include <string>
#include <iostream>
#include <sstream>

using std::string;
using namespace std;

class SpreadsheetCell_6_2_1 {
public:
	SpreadsheetCell_6_2_1() {
		mValue = 0;
		mString = "";
	}
	// because of this constructor, a default constructor has to be supplied
	SpreadsheetCell_6_2_1(double initialValue) {
		setValue(initialValue);
	}
	SpreadsheetCell_6_2_1(const string& initialValue) {
		setString(initialValue);
	}
	// copy constructor
	SpreadsheetCell_6_2_1(const SpreadsheetCell_6_2_1& src) :
		mValue(src.mValue), mString(src.mString) {}
	void setValue(double inValue) {
		mValue = inValue;
		mString = doubleToString(mValue);
		printCell(this);
	}
	double getValue() const {
		return mValue;
	}
	void setString(const string& inString) {
		mString = inString;
		mValue = stringToDouble(mString);
	}
	string getString() const {
		return mString;
	}
protected:
	string doubleToString(double inValue) const {
		ostringstream ostr;
		ostr << inValue;
		return ostr.str();
	}
	double stringToDouble(const string& inString) const {
		double temp;
		istringstream istr(inString);
		istr >> temp;
		if (istr.fail() || !istr.eof())
			return 0;
		return temp;
	}
	// function must be declared, when to be used by an object of this class
	friend void printCell(SpreadsheetCell_6_2_1*);

	double mValue;
	string mString;
};

inline void printCell(SpreadsheetCell_6_2_1* inCellp) {
	cout << "-> " << inCellp->getString() << endl;
}
