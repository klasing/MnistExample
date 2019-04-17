#include "pch.h"

inline void test_21_1_4(const int* const inProtectedInt, int* anotherPtr) {
	// BUG! Attempts to write to const value
	//*inProtectedInt = 7;
	// BUG! Attempts to write to const -pointer- value
	//inProtectedInt = anotherPtr;
}

inline void subParagraph_21_1_4() {
	cout << "Working with pointers" << endl;
	cout << "---------------------" << endl;

	cout << "a) A Mental Model for Pointers" << endl;
	cout << "b) Casting with Pointers" << endl;
	cout << "c) const with Pointers" << endl;
}