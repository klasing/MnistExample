//#pragma once
//
//#include "pch.h"
//
//class CounterNonInterleaved {
//public:
//	CounterNonInterleaved(int id, int numIterations) :
//		mId(id), mNumIterations(numIterations) {}
//	void operator()() const {
//		for (int i = 0; i < mNumIterations; ++i) {
//			lock_guard<mutex> lock(mMutex);
//			cout << "Counter " << mId << " has value ";
//			cout << i << endl;
//		}
//	}
//protected:
//	int mId;
//	int mNumIterations;
//	// the static member variable mMutex is declared in ModernCpp.cpp
//	static mutex mMutex;
//};
