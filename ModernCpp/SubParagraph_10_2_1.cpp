#include "pch.h"

#include <stdexcept>

inline int SafeDivide(int num, int den) {
	if (den == 0)
		throw invalid_argument("Divide by zero");
	return num / den;
}

inline void g_10_2_1() {
	throw 2;
}
inline void f_10_2_1() {
	try {
		g_10_2_1();
	}
	catch (int i) {
		cout << "-> caught in f: " << i << endl;
		// rethrow
		throw;
	}
}

inline void subParagraph_10_2_1() {
	cout << "Throwing and Catching Exceptions" << endl;
	cout << "--------------------------------" << endl;

	try {
		cout << "-> " << SafeDivide(5, 2) << endl;
		cout << "-> " << SafeDivide(10, 0) << endl;
		cout << "-> " << SafeDivide(3, 3) << endl;
	}
	catch (const invalid_argument& e) {
		cout << "-> Caught exception: " << e.what() << endl;
	}

	try {
		f_10_2_1();
	}
	catch (int i) {
		cout << "-> caught in main: " << i << endl;
	}
}