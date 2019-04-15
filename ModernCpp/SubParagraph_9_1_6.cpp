#include "pch.h"

#include <vector>
#include "SpreadsheetM.hpp"

// Increment value using lvalue reference parameter.
inline void incr(int& value) {
	cout << "-> increment with lvalue reference" << endl;
	++value;
}
// Increment value using rvalue reference parameter.
inline void incr(int&& value) {
	cout << "-> increment with rvalue reference" << endl;
	++value;
}

inline SpreadsheetM CreateObject() {
	return SpreadsheetM(3, 2);
}

inline void subParagraph_9_1_6() {
	cout << "Rvalue References" << endl;
	cout << "-----------------" << endl;

	int a = 10, b = 20;
	// Will call incr(int& value)
	incr(a);
	// Will call incr(int&& value)
	incr(a + b);
	// Will call incr(int&& value)
	incr(3);
	// Will call incr(int&& value)
	incr(std::move(b));

	cout << "a) Move Semantics" << endl;
	vector<SpreadsheetM> vec;
	for (int i = 0; i < 2; ++i) {
		cout << "-> Iteration " << i << endl;
		vec.push_back(SpreadsheetM(100, 100));
	}
	SpreadsheetM s(2, 3);
	s = CreateObject();
	SpreadsheetM s2(5, 6);
	// this needs the assignment operator, NOT the move assignment operator
	s2 = s;
}