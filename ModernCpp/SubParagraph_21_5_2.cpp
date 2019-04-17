#include "pch.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef  _DEBUG
	#ifndef  DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif //  _DEBUG

class Simple_ {
public:
	Simple_() { mIntPtr = new int(); }
	~Simple_() { delete mIntPtr; }
	void setIntPtr(int inInt) { *mIntPtr = inInt; }
protected:
	int* mIntPtr;
};

inline void doSomething(Simple_*& outSimplePtr) {
	// BUG! Doesn't delete the original.
	outSimplePtr = new Simple_();
}

inline void subParagraph_21_5_2() {
	cout << "Memory Leaks" << endl;
	cout << "------------" << endl;

	cout << "a) Finding and Fixing Memory Leaks in Windows with Visual C++" << endl;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// Allocate a Simple object
	Simple_* simplePtr = new Simple_();
	doSomething(simplePtr);
	// only cleans up the second object
	delete simplePtr;
	cout << "b) Finding and Fixing Memory Leaks in Linux with Valgrind" << endl;
}