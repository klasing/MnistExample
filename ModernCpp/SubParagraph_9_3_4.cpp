#include "pch.h"

// prototype
extern inline void ThirdPartyLibraryMethod(char* str);

inline void f_9_3_4(const char* str) {
	// cast away the const-ness
	ThirdPartyLibraryMethod(const_cast<char*>(str));
}

class Base_9_3_4 {
public:
	Base_9_3_4() {}
	virtual ~Base_9_3_4() {}
};
class Derived_9_3_4 : public Base_9_3_4 {
public:
	Derived_9_3_4() {}
	virtual ~Derived_9_3_4() {}
};

class X_9_3_4 {};
class Y_9_3_4 {};

inline void subParagraph_9_3_4() {
	cout << "Casts" << endl;
	cout << "-----" << endl;

	cout << "a) const_cast" << endl;
	cout << "b) static_cast" << endl;
	int i = 3;
	// avoid integer division
	double result = static_cast<double>(i) / 10;
	Base_9_3_4* b;
	Derived_9_3_4* d = new Derived_9_3_4();
	// Don't need a cast to go up the inheritance hierarchy
	b = d;
	// Need a cast to go down the hierarchy
	d = static_cast<Derived_9_3_4*>(b);
	Base_9_3_4 base;
	Derived_9_3_4 derived;
	Base_9_3_4& br = derived;
	Derived_9_3_4& dr = static_cast<Derived_9_3_4&>(br);
	// potentially catastrophic failure
	Base_9_3_4* b_ = new Base_9_3_4();
	Derived_9_3_4* d_ = static_cast<Derived_9_3_4*>(b);
	cout << "c) reinterpret_cast" << endl;
	X_9_3_4 x;
	Y_9_3_4 y;
	X_9_3_4* xp = &x;
	Y_9_3_4* yp = &y;
	// Need reinterpret cast for pointer conversion from unrelated classes
	// static_cast doesn't work.
	xp = reinterpret_cast<X_9_3_4*>(yp);
	// Need reinterpret cast for pointer conversion from unrelated pointers
	void* p = reinterpret_cast<void*>(xp);
	xp = reinterpret_cast<X_9_3_4*>(p);
	// Need reinterpret cast for reference conversion from unrelated classes
	// static_cast doesn't work.
	X_9_3_4& xr = x;
	Y_9_3_4& yr = reinterpret_cast<Y_9_3_4&>(x);
	cout << "d) dynamic_cast" << endl;
	Base_9_3_4* b_ex;
	Derived_9_3_4* d_ex = new Derived_9_3_4();
	b_ex = d_ex;
	d_ex = dynamic_cast<Derived_9_3_4*>(b);
	Base_9_3_4 base_;
	Derived_9_3_4 derived_;
	Base_9_3_4& br_ = base_;
	try {
		Derived_9_3_4& dr_ = dynamic_cast<Derived_9_3_4&>(br_);
	}
	catch (const bad_cast&) {
		cout << "-> Bad cast!\n";
	}
	cout << "e) Summary of Cast" << endl;
}