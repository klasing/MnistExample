#pragma once

#include <string>

class Muffin {
public:
	std::string getDescription() const {
		return mDesc;
	}
	void setDescription(const std::string& inDesc) {
		mDesc = inDesc;
	}
	int getSize() const {
		return mSize;
	}
	void setSize(int inSize) {
		mSize = inSize;
	}
	bool getHasChocolateChips() const {
		return mHasChocolateChips;
	}
	void setHasChocolateChips(bool inChips) {
		mHasChocolateChips = inChips;
	}
	void output() {
		printf("%s, Size is %d, %s", getDescription().c_str(), getSize(),
			(getHasChocolateChips() ? "has chips" : "no chips"));
	}
protected:
	std::string mDesc;
	int mSize;
	bool mHasChocolateChips;
};
