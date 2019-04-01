#pragma once

#include "pch.h"
#include <mutex>

class Data_22_4_3 {
public:
	void operator()() {
		call_once(mOnceFlag, &Data_22_4_3::init, this);
		// Do work
		cout << "-> Work" << endl;
	}
protected:
	void init() {
		cout << "-> init()" << endl;
		mMemory = new char[24];
	}

	mutable once_flag mOnceFlag;
	mutable char* mMemory;
};
