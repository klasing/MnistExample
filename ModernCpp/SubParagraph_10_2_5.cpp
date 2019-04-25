#include "pch.h"

#include <vector>
#include <exception>

// prototype
inline void readIntegerFile(const string& fileName, vector<int>& dest)
throw(invalid_argument, runtime_error);
// prevent throwing exceptions by the function
//inline void readIntegerFile(const string& fileName, vector<int>& dest)
//noexcept;

inline void foo() throw(invalid_argument, runtime_error) {
	// throw an unlisted exeption
	throw 5;
}

class Base_10_2_5 {
public:
	virtual void func() throw(exception) {
		cout << "-> Base_10_2_5!\n";
	}
};

class Derived_10_2_5 : public Base_10_2_5 {
public:
	//virtual void func() noexcept {
	//	cout << "Derived_10_2_5!\n";
	//}
	// or (you can't leave out the superclass exception)
	virtual void func() throw(exception, runtime_error) {
		cout << "Derived_10_2_5!\n";
	}
};

inline void subParagraph_10_2_5() {
	cout << "Throw List" << endl;
	cout << "----------" << endl;

	cout << "a) Unexpected Exceptions" << endl;
	try {
		foo();
	}
	catch (int x) {
		// won't be caught, according to the text book
		// in practice it will
		cerr << "-> Caught int" << endl;
	}
	cout << "b) Changing the Throw List in Overridden Methods" << endl;
	cout << "c) Are Throw Lists Useful?" << endl;
}