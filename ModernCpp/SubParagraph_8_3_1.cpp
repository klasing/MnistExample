#include "pch.h"

class Something {
public:
	Something() { cout << "-> 2"; }
	virtual ~Something() { cout << "-> 2"; }
};

class Parent {
public:
	Parent() { cout << "-> 1"; }
	virtual ~Parent() { cout << "-> 1"; }
};

class Child : public Parent {
public:
	Child() { cout << "-> 3"; }
	virtual ~Child() { cout << "-> 3"; }
protected:
	Something mDataMember;
};

inline int main_8_3_1() {
	Child myChild;
	// newline after last constructor
	cout << endl;
	return 0;
}

inline void subParagraph_8_3_1() {
	cout << "Parent Constructors" << endl;
	cout << "-------------------" << endl;

	main_8_3_1();
	// newline after last destructor
	cout << endl;
}