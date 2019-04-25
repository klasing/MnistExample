#include "pch.h"

#include <exception>
#include <cstdlib>

// example from:
// http://www.cplusplus.com/reference/exception/set_terminate/
inline void myTerminate() {
	cout << "-> Uncaught exception!" << endl;
	// forces abnormal termination
	abort();
}

inline void subParagraph_10_2_4() {
	cout << "Uncaught Exceptions" << endl;
	cout << "-------------------" << endl;

	set_terminate(myTerminate);
	// unhandled exception: calls terminate handler
	throw 0;
}
//#include <exception>
//#include <cstdlib>
//
//inline void myTerminate() {
//	cout << "-> Uncaught exception!" << endl;
//	exit(1);
//}
//
//inline void subParagraph_10_2_4() {
//	cout << "Uncaught Exceptions" << endl;
//	cout << "-------------------" << endl;
//
//	// this example is not working according to my expectations
//	terminate_handler th = set_terminate(myTerminate);
//	try {
//		throw 1;
//	}
//	catch (...) {
//		if (th != nullptr) {
//			terminate_handler();
//			abort();
//		}
//		else
//			terminate();
//	}
//	// normal termination code
//	set_terminate(th);
//}