#include "pch.h"

#include <stdexcept>
#include <new>

class GamePiece_10_6 {
};

class GameBoard_10_6 {
public:
	// general-purpose GameBoard allows users to specify its dimensions
	GameBoard_10_6(int inWidth = kDefaultWidth,
		int inHeight = kDefaultHeight) throw(bad_alloc) 
		: mWidth(inWidth), mHeight(inHeight) {
		int i = 0;
		mCells = new GamePiece_10_6* [mWidth];
		try {
			for (i = 0; i < mWidth; i++)
				mCells[i] = new GamePiece_10_6[mHeight];
		}
		catch (...) {
			// Cleanup any memory we already allocated, because  the destructor
			// will never be called. The upper bound of the for loop is the
			// indec of the last element in the mCells array that we tried
			// to allocate (the one that failed). All indices before that
			// one store pointers to allocated memory that must be freed.
			for (int j = 0; j < i; j++)
				delete[] mCells[j];
			delete[] mCells;
			mCells = nullptr;
			// Translate any exception to bad_alloc.
			throw bad_alloc();
		}
	}
	// Copy constructor
	GameBoard_10_6(const GameBoard_10_6& src) throw(bad_alloc) {
		copyFrom(src);
	}
	virtual ~GameBoard_10_6() noexcept {
		// Free the old memory
		for (int i = 0; i < mWidth; i++)
			delete[] mCells[i];
		delete mCells;
		mCells = nullptr;
	}
	// Assignment operator
	GameBoard_10_6& operator=(const GameBoard_10_6& rhs) throw(bad_alloc) {
		// Check for self-assignment
		if (this == &rhs)
			return *this;
		// Free the old memory
		for (int i = 0; i < mWidth; i++)
			delete[] mCells[i];
		delete mCells;
		mCells = nullptr;
		// Copy the new memory
		copyFrom(rhs);
		return *this;
	}
	void setPieceAt(int x, int y, const GamePiece_10_6& inPiece) 
		throw(out_of_range) {

		// Check for out of range arguments
		if (x < 0)
			throw out_of_range("Gameboard::setPieceAt: x-coord negative");
		if (x >= mWidth)
			throw out_of_range("Gameboard::setPieceAt: x-coord beyond width");
		if (y < 0)
			throw out_of_range("Gameboard::setPieceAt: y-coord negative");
		if (x >= mHeight)
			throw out_of_range("Gameboard::setPieceAt: y-coord beyond height");

		mCells[x][y] = inPiece;
	}
	GamePiece_10_6& getPieceAt(int x, int y) throw(out_of_range) {
		return mCells[x][y];
	}
	const GamePiece_10_6& getPieceAt(int x, int y) const 
		throw(out_of_range) {
		return mCells[x][y];
	}
	int getHeight() const noexcept { return mHeight; }
	int getWidth() const noexcept { return mWidth; }
	static const int kDefaultWidth = 100;
	static const int kDefaultHeight = 100;
protected:
	void copyFrom(const GameBoard_10_6& src) throw(out_of_range) {
		int i = 0;
		mWidth = src.mWidth;
		mHeight = src.mHeight;
		mCells = new GamePiece_10_6* [mWidth];
		try {
			for (i = 0; i < mWidth; i++)
				mCells[i] = new GamePiece_10_6[mHeight];
		}
		catch (...) {
			// Clean up any memory we already allocated.
			// If this function is called from the copy constructor,
			// the destructor is never called.
			// Use the same loop upper bound as described in the constructor.
			for (int j = 0; j < i; j++)
				delete[] mCells[j];
			delete[] mCells;
			// Set mCells and mWidth to values that will allow the
			// destructor to run without harming anything.
			// This function is called from operator=, in which case the
			// object was already constructed, so the destructor will be
			// called at some point.
			mCells = nullptr;
			mWidth = 0;
			throw bad_alloc();

		}
		for (i = 0; i < mWidth; i++)
			for (int j = 0; j < mHeight; j++)
				mCells[i][j] = src.mCells[i][j];
	}
	// Objects dynamically allocate space for the game pieces.
	GamePiece_10_6** mCells;
	int mWidth, mHeight;
};

inline void paragraph_10_6() {
	cout << "Putting It All Together" << endl;
	cout << "-----------------------" << endl;
}