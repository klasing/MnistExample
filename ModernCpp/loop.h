//#pragma once
//
//#include "pch.h"
//
//template<int i, typename FuncType>
//class Loop {
//public:
//	static inline void Do(FuncType func) {
//		Loop<i - 1, FuncType>::Do(func);
//		func(i);
//	}
//};
//
//template<typename FuncType>
//class Loop<-1, FuncType> {
//public:
//	static inline void Do(FuncType func) {}
//};
