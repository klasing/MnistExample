#include "pch.h"

class MyClass {
public:
	void foo(int i) {}
	// prevents calling the method with a double as a parameter
	void foo(double d) = delete;
};

inline void subParagraph_7_3_3() {
	cout << "Method Overloading" << endl;
	cout << "------------------" << endl;

	MyClass c;
	c.foo(123);
	// not allowed
	//c.foo(1.23);
}