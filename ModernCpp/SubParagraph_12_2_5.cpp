#include "pch.h"

#include <array>

inline void subParagraph_12_2_5() {
	cout << "array" << endl;
	cout << "-----" << endl;

	// Create array of 3 integers and initialize them
	// with the given intializer_list using uniform initialization.
	array<int, 3> arr = { 9,8,7 };
	// Output the size of the array.
	cout << "-> Array size = " << arr.size() << endl;
	// Output the contents of the array using iterators.
	for (auto iter = arr.cbegin(); iter != arr.cend(); ++iter)
		cout << "-> " << *iter << endl;

	cout << "-> Performing arr.fill(3)..." << endl;
	// Use the fill method to change the contents of the array.
	arr.fill(3);
	// Output the contents using the range-based for loop.
	for (auto& i : arr)
		cout << "-> " << i << endl;
}