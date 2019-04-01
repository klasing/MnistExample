#pragma once

#include "pch.h"

#include <mutex>

class Counter_22_4_4_a {
public:
	Counter_22_4_4_a(int id, int numIterations)
		: mId(id), mNumIterations(numIterations) {}
	void operator()() const {
		for (int i = 0; i < mNumIterations; ++i) {
			lock_guard<mutex> lock(mMutex);
			cout << "-> Counter_22_4_4 " << mId << " has value ";
			cout << i << endl;
		}
	}
protected:
	int mId;
	int mNumIterations;
	static mutex mMutex;
};