#include "pch.h"

#include <map>

class Nothing {
public:
	Nothing() { cout << "Nothing::Nothing()" << endl; }
	~Nothing() { cout << "Nothing::~Nothing()" << endl; }
};

inline void doubleDelete() {
	Nothing* myNothing = new Nothing();
	shared_ptr<Nothing> smartPtr1(myNothing);
	shared_ptr<Nothing> smartPtr2(myNothing);
}

inline void noDoubleDelete() {
	Nothing* myNothing = new Nothing();
	shared_ptr<Nothing> smartPtr1(myNothing);
	shared_ptr<Nothing> smartPtr2 = smartPtr1;
}

class NothingEx {
public:
	NothingEx() { sNumAllocations++; }
	~NothingEx() { sNumDeletions++; }
	static int sNumAllocations;
	static int sNumDeletions;
};
// the global declaration for the statics has gone into
// the ModernCpp.cpp file

template <typename T>
class SuperSmartPointer {
public:
	explicit SuperSmartPointer(T* inPtr) { initPointer(inPtr); }
	virtual ~SuperSmartPointer() { finalizePointer(); }
	SuperSmartPointer(const SuperSmartPointer<T>& src) {
		initPointer(src.mPtr);
	}
	SuperSmartPointer<T>& operator=(const SuperSmartPointer<T>& rhs) {
		if (this == &rhs)
			return *this;
		finalizePointer();
		initPointer(rhs.mPtr);
		return *this;
	}
	const T& operator*() const { return *mPtr; }
	const T* operator->() const { return mPtr; }
	T& operator*() { return mPtr; }
	T* operator->() { return mPtr; }
	operator void*() const { return mPtr; }
protected:
	T* mPtr;
	static map<T*, int> sRefCountMap;
	void finalizePointer() {
		if (sRefCountMap.find(mPtr) == sRefCountMap.end()) {
			throw runtime_error("ERROR: Missing entry in map!");
		}
		sRefCountMap[mPtr]--;
		if (sRefCountMap[mPtr] == 0) {
			// No more references to this object--delete it and remove from map
			sRefCountMap.erase(mPtr);
			delete mPtr;
			mPtr = nullptr;
		}
	}
	void initPointer(T* inPtr) {
		mPtr = inPtr;
		if (sRefCountMap.find(mPtr) == sRefCountMap.end())
			sRefCountMap[mPtr] = 1;
		else
			sRefCountMap[mPtr]++;
	}
};

template <typename T>
map<T*, int> SuperSmartPointer<T>::sRefCountMap;

inline void subParagraph_21_4_3() {
	cout << "Writing Your Own Smart Pointer Class" << endl;
	cout << "------------------------------------" << endl;

	cout << "a) The Need for Reference Counting" << endl;
	// this will cause:
	// HEAP[ModernCpp.exe]: Invalid address specified to RtlValidateHeap(01430000, 01445B88)
	// ModernCpp.exe has triggered a breakpoint.
	//doubleDelete();
	noDoubleDelete();
	cout << "b) The SuperSmartPointer" << endl;
	cout << "c) Unit Testing the SuperSmartPointer" << endl;
	NothingEx* myNothingEx = new NothingEx();
	{
		SuperSmartPointer<NothingEx> ptr1(myNothingEx);
		SuperSmartPointer<NothingEx> ptr2(myNothingEx);
	}
	if (NothingEx::sNumAllocations != NothingEx::sNumDeletions)
		cout << "-> TEST FAILED: " << NothingEx::sNumAllocations <<
		" allocation and " << NothingEx::sNumDeletions <<
		" deletions" << endl;
	else
		cout << "-> TEST PASSED" << endl;
	
	cout << "d) Enhancing This Implementation" << endl;
}