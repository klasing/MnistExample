#pragma once

class SpreadsheetM {
public:
	SpreadsheetM(int inWidth, int inHeight) {
		cout << "-> Normal constructor" << endl;
	}
	// Move constructor
	SpreadsheetM(SpreadsheetM&& src) {
		cout << "-> Move constructor" << endl;
	}
	// Assignment operator
	SpreadsheetM& operator=(SpreadsheetM& rhs) {
		cout << "-> Assignment operator" << endl;
		return *this;
	}
	// Move assignment
	SpreadsheetM& operator=(SpreadsheetM&& rhs) {
		cout << "-> Move assignment operator" << endl;
		return *this;
	}
};

