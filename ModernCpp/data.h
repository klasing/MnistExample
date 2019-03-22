//#pragma once
//
//#include "pch.h"
//
//class Data {
//public:
//	void operator()() {
//		call_once(mOnceFlag, &Data::init, this);
//		// Do work
//		cout << "Work" << endl;
//	}
//protected:
//	void init() {
//		cout << "init()" << endl;
//		mMemory = new char[24];
//	}
//
//	mutable once_flag mOnceFlag;
//	mutable char* mMemory;
//};