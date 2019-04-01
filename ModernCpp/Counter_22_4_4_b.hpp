#pragma once

#include "pch.h"

#include <mutex>
#include <chrono>

class Counter_22_4_4_b{
public:
	Counter_22_4_4_b(int id, int numIterations)
		: mId(id), mNumIterations(numIterations) {}
	void operator()() const {
		for (int i = 0; i < mNumIterations; ++i) {
			unique_lock<timed_mutex> lock(mTimedMutex,
				chrono::milliseconds(200));
			if (lock) {
				cout << "-> Counter_22_4_4 " << mId << " has value ";
				cout << i << endl;
				// insert a time delay to let fail aquiring a lock
				// usable only after FURTHER INVESTIGATION
				//double d = 0;
				//for (int j = 0; j < 100000; ++i)
				//	d += sqrt(sin(i) * cos(i));
			}
			else {
				// lock not aquired in 200 ms
				cout << "-> Counter_22_4_4 " << mId << " lock not aquired in 200 ms" << endl;
			}
		}
	}
protected:
	int mId;
	int mNumIterations;
	static timed_mutex mTimedMutex;
};
