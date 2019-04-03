#pragma once

#include <string>
#include <iostream>
#include <sstream>

using std::string;
using namespace std;

class SpreadsheetCell {
public:
	friend class Spreadsheet;
	// TODO does not work (or, instead of above)
	//friend void Spreadsheet::setCellAt(int x, int y,
	//	const SpreadsheetCell& cell);
	//friend bool checkSpreadsheetCell(const SpreadsheetCell& cell) {
	//	return !(cell.mString.empty());
	//}
	SpreadsheetCell() {
		mValue = 0;
		mString = "";
	}
	// because of this constructor, a default constructor has to be supplied
	SpreadsheetCell(double initialValue) {
		setValue(initialValue);
	}
	explicit SpreadsheetCell(const string& initialValue) {
		setString(initialValue);
	}
	// copy constructor
	SpreadsheetCell(const SpreadsheetCell& src) :
		mValue(src.mValue), mString(src.mString) {}
	// assignment operator
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs) {
		if (this == &rhs)
			return *this;
		mValue = rhs.mValue;
		mString = rhs.mString;
		return *this;

	}
	const SpreadsheetCell add(const SpreadsheetCell& cell) const {
		SpreadsheetCell newCell;
		// update mValue and mString
		newCell.set(mValue + cell.mValue);
		return newCell;
	}
	// is not communitative for addition, solution: a global operator+
	// function (as a friend function for this class)
	//const SpreadsheetCell operator+(const SpreadsheetCell& cell) const {
	//	SpreadsheetCell newCell;
	//	// update mValue and mString
	//	newCell.set(mValue + cell.mValue);
	//	return newCell;
	//}
	// is not communitative for addition, solution: a global operator+
	// function (as a friend function for this class)
	//const SpreadsheetCell operator+(double rhs) const {
	//	return SpreadsheetCell(mValue + rhs);
	//}
	// function must be declared, in order to be used by an object of this class
	friend const SpreadsheetCell operator+(const SpreadsheetCell& lhs,
		const SpreadsheetCell& rhs);
	// overloading arithmetic operators
	friend const SpreadsheetCell operator-(const SpreadsheetCell& lhs,
		const SpreadsheetCell& rhs);
	friend const SpreadsheetCell operator*(const SpreadsheetCell& lhs,
		const SpreadsheetCell& rhs);
	friend const SpreadsheetCell operator/(const SpreadsheetCell& lhs,
		const SpreadsheetCell& rhs);
	// overloading the arithmetic shorthand operators
	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs) {
		// Call set to update mValue and mString
		set(mValue + rhs.mValue);
		return *this;
	}
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs) {
		// Call set to update mValue and mString
		set(mValue - rhs.mValue);
		return *this;
	}
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs) {
		// Call set to update mValue and mString
		set(mValue * rhs.mValue);
		return *this;
	}
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs) {
		if (rhs.mValue == 0)
			throw invalid_argument("Divide by zero.");
		// Call set to update mValue and mString
		set(mValue / rhs.mValue);
		return *this;
	}
	// overloading comparison operators
	friend bool operator==(const SpreadsheetCell& lhs,
		const SpreadsheetCell& rhs);
	friend bool operator<(const SpreadsheetCell& lhs,
		const SpreadsheetCell& rhs);
	friend bool operator>(const SpreadsheetCell& lhs,
		const SpreadsheetCell& rhs);
	friend bool operator!=(const SpreadsheetCell& lhs,
		const SpreadsheetCell& rhs);
	friend bool operator<=(const SpreadsheetCell& lhs,
		const SpreadsheetCell& rhs);
	friend bool operator>=(const SpreadsheetCell& lhs,
		const SpreadsheetCell& rhs);
	void setValue(double inValue) {
		mValue = inValue;
		mString = doubleToString(mValue);
		printCell(this);
	}
	// overloading setValue() method
	void set(double inValue) {
		mValue = inValue;
		mString = doubleToString(mValue);
		printCell(this);
	}
	// the keyword inline is redundant, because the method definition is
	// is placed directly in the declaration 
	inline double getValue() const {
		// this const method changes a MUTABLE data member: mNumAccesses
		mNumAccesses++;
		return mValue;
	}
	void setString(const string& inString) {
		mString = inString;
		mValue = stringToDouble(mString);
	}
	// overloading setString() method
	void set(const string& inString) {
		mString = inString;
		mValue = stringToDouble(mString);
	}
	// the keyword inline is redundant, because the method definition is
	// is placed directly in the declaration 
	inline string getString() const {
		// this const method changes a MUTABLE data member: mNumAccesses
		mNumAccesses++;
		return mString;
	}
	typedef enum {Red=1, Green, Blue, Yellow} Colors;
	void setColor(Colors color) {
		mColor = color;
	}
protected:
	static string doubleToString(double inValue) {
		ostringstream ostr;
		ostr << inValue;
		return ostr.str();
	}
	static double stringToDouble(const string& inString) {
		double temp;
		istringstream istr(inString);
		istr >> temp;
		if (istr.fail() || !istr.eof())
			return 0;
		return temp;
	}
	// function must be declared, in order to be used by an object of this class
	friend void printCell(SpreadsheetCell*);

	double mValue;
	string mString;
	mutable int mNumAccesses = 0;
	Colors mColor = Red;
};

inline void printCell(SpreadsheetCell* inCellp) {
	cout << "-> " << inCellp->getString() << endl;
}
inline const SpreadsheetCell operator+(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs) {
	SpreadsheetCell newCell;
	// update mValue and mString
	newCell.set(lhs.mValue + rhs.mValue);
	return newCell;
}
inline const SpreadsheetCell operator-(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs) {
	SpreadsheetCell newCell;
	// update mValue and mString
	newCell.set(lhs.mValue - rhs.mValue);
	return newCell;
}
inline const SpreadsheetCell operator*(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs) {
	SpreadsheetCell newCell;
	// update mValue and mString
	newCell.set(lhs.mValue * rhs.mValue);
	return newCell;
}
inline const SpreadsheetCell operator/(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs) {
	if (rhs.mValue == 0)
		throw invalid_argument("Divide by zero.");
	SpreadsheetCell newCell;
	// update mValue and mString
	newCell.set(lhs.mValue / rhs.mValue);
	return newCell;
}
// CAUTION performing equality or inequality test on type double
// is not a good idea
// an epsilon test should be used instead!!!
inline bool operator==(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs) {
	return (lhs.mValue == rhs.mValue);
}
inline bool operator<(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs) {
	return (lhs.mValue < rhs.mValue);
}
inline bool operator>(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs) {
	return (lhs.mValue > rhs.mValue);
}
inline bool operator!=(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs) {
	return (lhs.mValue != rhs.mValue);
}
inline bool operator<=(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs) {
	return (lhs.mValue <= rhs.mValue);
}
inline bool operator>=(const SpreadsheetCell& lhs,
	const SpreadsheetCell& rhs) {
	//return (lhs.mValue >= rhs.mValue);
	// or by using the operator< function
	return !(lhs < rhs);
}
