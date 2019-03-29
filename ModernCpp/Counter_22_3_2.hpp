#pragma once

#include "pch.h"

class Counter_22_3_2 {
public:
	Counter_22_3_2(int id, int numIterations)
		: mId(id), mNumIterations(numIterations) {}
	void operator()() const {
		for (int i = 0; i < mNumIterations; ++i) {
			cout << "-> Counter " << mId << " has value ";
			cout << i << endl;
		}
	}
protected:
	int mId;
	int mNumIterations;
};