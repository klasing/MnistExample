#include "pch.h"

inline void subParagraph_9_1_1() {
	cout << "Reference Variables" << endl;
	cout << "-------------------" << endl;

	int x = 3;
	int& xRef = x;
	xRef = 10;
	cout << "-> x is " << x << " xRef is " << xRef << endl;

	// does not work
	//int& unnamedRef1 = 5;
	// works
	const int& unnamedRef2 = 5;

	x = 3;
	int y = 4;
	//int& xRef = x;
	// Changes value of x to 4. Doesn't make xRef refer to y.
	xRef = y;

	x = 3;
	int z = 5;
	//int& xRef = x;
	int& zRef = z;
	// Assigns values, not references
	zRef = xRef;

	cout << "a) References to Pointers and Pointers to References" << endl;
	int* intP;
	int*& ptrRef = intP;
	ptrRef = new int;
	*ptrRef = 5;
	cout << "-> intP is " << *intP << endl;

	x = 3;
	//int& xRef = x;
	// Address of a reference is pointer to a value 
	int* xPtr = &xRef;
	*xPtr = 100;
	cout << "-> x is " << x << endl;

	// DOES NOT COMPILE
	//int&& xDoubleRef = xRef;
	//int&* refPtr = &xRef;
}