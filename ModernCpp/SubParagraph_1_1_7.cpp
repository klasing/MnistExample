#include "pch.h"

inline void rangeBasedForLoop() {
	int arr[] = { 1, 2, 3, 4 };

	cout << "-> ";
	for (auto& i : arr)
		cout << i << " ";
	cout << endl;
}

inline void subParagraph_1_1_7() {
	cout << "Loops" << endl;
	cout << "-----" << endl;

	cout << "a) The while Loop" << endl;
	cout << "b) The do/while Loop" << endl;
	cout << "c) The for Loop" << endl;
	cout << "   C++11 The Range-Based for Loop" << endl;

	rangeBasedForLoop();
}