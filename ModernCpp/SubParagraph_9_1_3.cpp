#include "pch.h"

inline void swap(int& first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}

inline void subParagraph_9_1_3() {
	cout << "Reference Parameters" << endl;
	cout << "--------------------" << endl;

	int x = 5, y = 6;
	swap(x, y);

	// DOES NOT COMPILE
	//swap(3, 4);

	cout << "a) References from Pointers" << endl;
	x = 5; y = 6;
	int *xp = &x, *yp = &y;
	swap(*xp, *yp);

	cout << "b) Pass-By-Reference versus Pass-By-Value" << endl;
}