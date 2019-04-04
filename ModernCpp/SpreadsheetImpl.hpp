#pragma once

#include "SpreadsheetCell.hpp"

// forward declaration
class SpreadsheetApplication;
class SpreadsheetImpl {
public:
	SpreadsheetImpl(const SpreadsheetApplication& theApp,
		int inWidth = kMaxWidth, int inHeight = kMaxHeight) :
		mWidth(inWidth < kMaxWidth ? inWidth : kMaxWidth), 
		mHeight(inHeight < kMaxHeight ? inHeight : kMaxHeight),
		mTheApp(theApp) {
		mId = sCounter++;
		mCells = new SpreadsheetCell*[mWidth];
		for (int i = 0; i < mWidth; i++)
			mCells[i] = new SpreadsheetCell[mHeight];
	}
	SpreadsheetImpl(const SpreadsheetImpl& src) :
		mTheApp(src.mTheApp) {
		mId = sCounter++;
		copyFrom(src);
	}
	~SpreadsheetImpl() {
		for (int i = 0; i < mWidth; i++)
			delete[] mCells[i];
		delete[] mCells;
		mCells = nullptr;
	}
	void setCellAt(int x, int y, const SpreadsheetCell& cell) {
		if (!inRange(x, mWidth) || !inRange(y, mHeight))
			throw std::out_of_range("");
		mCells[x][y] = cell;
	}
	SpreadsheetCell getCellAt(int x, int y) {
		if (!inRange(x, mWidth) || !inRange(y, mHeight))
			throw std::out_of_range("");
		return mCells[x][y];
	}

	static const int kMaxHeight = 100;
	static const int kMaxWidth = 100;
//private:
	SpreadsheetImpl& operator=(const SpreadsheetImpl& rhs) {
		// Check for self-assignment
		if (this == &rhs) {
			return *this;
		}
		// Free the old memory.
		for (int i = 0; i < mWidth; i++)
			delete[] mCells[i];
		delete[] mCells;
		mCells = nullptr;
		copyFrom(rhs);
		return *this;
	}
	int getId() const { return mId; }
protected:
	bool inRange(int val, int upper) {
		if (val > upper)
			return false;
		return true;
	}
	void copyFrom(const SpreadsheetImpl& src) {
		mWidth = src.mWidth;
		mHeight = src.mHeight;
		mCells = new SpreadsheetCell*[mWidth];
		for (int i = 0; i < mWidth; i++)
			mCells[i] = new SpreadsheetCell[mHeight];
		for (int i = 0; i < mWidth; i++)
			for (int j = 0; j < mHeight; j++)
				mCells[i][j] = src.mCells[i][j];
	}

	int mWidth, mHeight;
	SpreadsheetCell** mCells;
	static int sCounter;
	int mId;
	const SpreadsheetApplication& mTheApp;
};