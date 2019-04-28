#include "pch.h"

#include <vector>

typedef vector<string> StringVector;
inline void processVector(const StringVector& vec) { /* omitted */ }

inline void subParagraph_9_3_1() {
	cout << "typedefs" << endl;
	cout << "--------" << endl;

	typedef int* IntPtr;
	int* p1;
	IntPtr p2 = nullptr;
	p1 = p2;
	p2 = p1;

	StringVector myVector;
}