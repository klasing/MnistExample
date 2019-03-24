#include "pch.h"

#include <array>

inline void stdArray() {
	array<int, 3> arr = { 9, 8, 7 };

	cout << "-> Array size = " << arr.size() << endl;
	cout << "-> ";
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
}

inline void subParagraph_1_1_8() {
	cout << "Arrays" << endl;
	cout << "------" << endl;

	cout << "   C++11 std::array" << endl;

	stdArray();
}