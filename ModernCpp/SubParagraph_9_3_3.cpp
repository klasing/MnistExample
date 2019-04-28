#include "pch.h"

// suppose the function prototype
inline int someFunction(char c, double d) { return 0; }

inline void subParagraph_9_3_3() {
	cout << "Type Aliases" << endl;
	cout << "------------" << endl;

	using MyInt = int;
	// equivalent to:
	typedef int MyInt;

	MyInt i = 123;

	// define a pointer pFunc to this function
	int (*pFunc)(char, double) = &someFunction;
	// simplify the definition
	typedef int(*FuncType)(char, double);
	FuncType pFunc_ = &someFunction;
	// simplify the definition, with using  
	using FuncType_ = int (*)(char, double);
	FuncType_ pFunc_ex = &someFunction;
}