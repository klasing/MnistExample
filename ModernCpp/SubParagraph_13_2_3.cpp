#include "pch.h"

#include <functional>

inline function<int(void)> multiplyBy2Lambda(int x) {
	//return [=]()->int { return 2 * x; };
	// or even shorter
	return [=]{ return 2 * x; };
}

inline void subParagraph_13_2_3() {
	cout << "Lambda Expressions as Return Type" << endl;
	cout << "---------------------------------" << endl;

	//function<int(void)> fn = multiplyBy2Lambda(5);
	// or with a type auto
	auto fn = multiplyBy2Lambda(5);
	cout << "-> Two times " << 5 << " is " << fn() << endl;
}