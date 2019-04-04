#pragma once

#include "SpreadsheetImpl.hpp"
#include "SpreadsheetApplication.hpp"
#include "SpreadsheetCell.hpp"

// forward declarations
//class SpreadsheetImpl;
//class SpreadsheetApplication;
class Spreadsheet {
	Spreadsheet(const SpreadsheetApplication& theApp, int inWidth,
		int inHeight) {
		mImpl = new SpreadsheetImpl(theApp, inWidth, inHeight);

	}
	Spreadsheet(const SpreadsheetApplication& theApp) {
		mImpl = new SpreadsheetImpl(theApp);
	}
	Spreadsheet(const Spreadsheet& src) {
		mImpl = new SpreadsheetImpl(*(src.mImpl));
	}
	~Spreadsheet() {
		delete mImpl;
		mImpl = nullptr;
	}
	Spreadsheet& operator=(const Spreadsheet& rhs) {
		*mImpl = (rhs.mImpl);
		return *this;
	}
	void setCellAt(int x, int y, const SpreadsheetCell& inCell) {
		mImpl->setCellAt(x, y, inCell);
	}
	SpreadsheetCell getCellAt(int x, int y) {
		return mImpl->getCellAt(x, y);
	}
	int getId() const {
		return mImpl->getId();
	}
protected:
	SpreadsheetImpl* mImpl;
};