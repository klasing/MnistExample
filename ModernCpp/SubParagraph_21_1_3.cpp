#include "pch.h"

class Simple_21_1_3 {
public:
	Simple_21_1_3() { cout << "-> Simple constructor called!" << endl; }
	virtual ~Simple_21_1_3() { cout << "-> Simple destructor called!" << endl; }
};

inline char** allocateCharacterBoard(size_t xDimension, size_t yDimension) {
	// Allocate first dimension
	char** myArray = new char*[xDimension];
	for (size_t i = 0; i < xDimension; i++)
		// Allocate ith subarray
		myArray[i] = new char[yDimension];
	return myArray;
}

inline void releaseCharacterBoard(char** myArray, size_t xDimension) {
	for (size_t i = 0; i < xDimension; i++)
		// delete ith subarray
		delete[] myArray[i];
	// Delete first dimension
	delete[] myArray;
}

inline void subParagraph_21_1_3() {
	cout << "Arrays" << endl;
	cout << "------" << endl;

	cout << "a) Arrays of Basic Types" << endl;
	cout << "b) Arrays of Objects" << endl;
	Simple_21_1_3* mySimpleArray = new Simple_21_1_3[4];
	// Use mySimpleArray
	delete[] mySimpleArray;
	mySimpleArray = nullptr;

	size_t arrSize = 4;
	Simple_21_1_3** mySimplePtrArray = new Simple_21_1_3*[arrSize];
	// Allocate an object for each pointer.
	for (size_t i = 0; i < arrSize; i++)
		mySimplePtrArray[i] = new Simple_21_1_3();
	// Use mySimplePtrArray...
	// Delete each allocated object.
	for (size_t i = 0; i < arrSize; i++)
		delete mySimplePtrArray[i];
	// Delete the array itself
	delete[] mySimplePtrArray;
	mySimplePtrArray = nullptr;

	cout << "c) Deleting Arrays" << endl;
	cout << "d) Multi-Dimensional Arrays" << endl;
	char board[3][3];
	// Test code
	// X puts marker in position (0, 0)
	board[0][0] = 'X';
	// O puts marker in position (2, 1)
	board[2][1] = 'O';
	cout << "   d.1) Multi-Dimensional Stack Arrays" << endl;
	cout << "   d.2) Multi-Dimensional Heap Arrays" << endl;

}