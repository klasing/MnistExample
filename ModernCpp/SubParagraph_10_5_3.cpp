#include "pch.h"

#include <stdexcept>

class SubObject_10_5_3 {
public:
	SubObject_10_5_3(int i) throw(runtime_error) {
		throw runtime_error("Exception by SubObject ctor");
	}
};

class MyClass_10_5_3 {
public:
	MyClass_10_5_3() throw(runtime_error) 
	try
		: mSubObject(42) {
		/* ... constructor body ... */
	}
	catch (const exception& e) {
		cout << "-> function-try-block caught: '" << e.what() << "'" << endl;
	}
protected:
	SubObject_10_5_3 mSubObject;
};

inline void subParagraph_10_5_3() {
	cout << "Function-Try-Blocks for Constructors" << endl;
	cout << "------------------------------------" << endl;

	try {
		MyClass_10_5_3 m;
	}
	catch (const exception & e) {
		cout << "-> subParagraph_10_5_3() caught: '" << e.what() << "'" << endl;
	}
}