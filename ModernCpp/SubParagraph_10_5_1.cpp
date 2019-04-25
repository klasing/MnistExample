#include "pch.h"

#include <new>

class PleaseTerminateMe {};
inline void myNewHandler() {
	cerr << "-> " << __FILE__ << "(" << __LINE__
		<< "): Unable to allocate memory!" << endl;
	throw PleaseTerminateMe();
}

inline void subParagraph_10_5_1() {
	cout << "Memory Allocation Errors" << endl;
	cout << "------------------------" << endl;

	const int numInts = 10000;
	int* ptr;
	try {
		ptr = new int[numInts];
	}
	catch (const bad_alloc & e) {
		cerr << "-> " << __FILE__ << "(" << __LINE__
			<< "): Unable to allocate memory!" << endl;
		// Handle memory allocation failure.
	}
	// Proceed with function that assumes memory has been allocated.

	cout << "a) Non-Throwing new" << endl;
	ptr = new(nothrow) int[numInts];
	if (ptr == nullptr) {
		cerr << "-> " << __FILE__ << "(" << __LINE__
			<< "): Unable to allocate memory!" << endl;
		// Handle memory allocation failure.
	}
	// Proceed with function that assumes memory has been allocated.

	cout << "b) Customizing Memory Allocation Failure Behavior" << endl;
	try {
		// Set the new handler and save the old.
		new_handler oldHandler = set_new_handler(myNewHandler);
		// Generate allocation error
		int numInts = numeric_limits<int>::max();
		ptr = new int[numInts];
		// reset the old handler
		set_new_handler(oldHandler);
	}
	catch (const PleaseTerminateMe&) {
		cerr << "-> " << __FILE__ << "(" << __LINE__
			<< "): Terminating program." << endl;
	}
}