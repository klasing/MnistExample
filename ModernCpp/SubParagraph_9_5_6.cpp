#include "pch.h"

class IntWrapper {
public:
	IntWrapper(int i) : mInt(i) {}
	//operator int() const { return mInt; }
	// make explicit method
	explicit operator int() const { return mInt; }
private:
	int mInt;
};

inline void subParagraph_9_5_6() {
	cout << "Explicit Conversion Operators" << endl;
	cout << "-----------------------------" << endl;

	IntWrapper c(123);
	// Error, because of explicit int() operator
	//int iC1 = c;
	// it has to be
	int iC1 = static_cast<int>(c);
	// or
	int iC2 = int(c);
}