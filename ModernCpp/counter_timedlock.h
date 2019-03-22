//#pragma once
//
//#include "pch.h"
//
//class CounterTimedLock {
//public:
//	CounterTimedLock(int id, int numIterations) :
//		mId(id), mNumIterations(numIterations) {}
//	void operator()() const {
//		for (int i = 0; i < mNumIterations; ++i) {
//			unique_lock<timed_mutex> lock(mTimedMutex,
//				chrono::milliseconds(200));
//			if (lock) {
//				cout << "Counter " << mId << " has value ";
//				cout << i << endl;
//			} else
//				cout << "Lock not aquired within 200 ms" << endl;
//		}
//	}
//protected:
//	int mId;
//	int mNumIterations;
//	// the static member variable mMutex is declared in ModernCpp.cpp
//	static timed_mutex mTimedMutex;
//};
