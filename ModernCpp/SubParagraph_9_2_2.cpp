#include "pch.h"

// prototype, function define in ModernCpp.cpp
inline void f_9_2_2();
extern int xExtern;
inline void performTask_9_2_2() {
	static bool inited = false;
	if (!inited) {
		cout << "-> initing\n";
		// Perform initialization.
		inited = true;
	}
	// Perform the desired task.
}

inline void subParagraph_9_2_2() {
	cout << "The static Keyword" << endl;
	cout << "------------------" << endl;

	cout << "a) static Data Members and Methods" << endl;
	cout << "b) static Linkage" << endl;
	f_9_2_2();
	cout << "c) The extern Keyword" << endl;
	cout << "-> " << xExtern << endl;
	cout << "d) static Variables in Functions" << endl;
	// with initialization
	performTask_9_2_2();
	// without initialization
	performTask_9_2_2();
}