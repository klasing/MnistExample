#include "pch.h"

#include <string>

template<typename T>
class MyArray {
public:
	MyArray(size_t size) : mSize(size), mArray(nullptr) {
		mArray = new T[size];
	}
	virtual ~MyArray() {
		if (mArray) {
			delete[] mArray;
			mArray = nullptr;
		}
	}
	size_t getSize() const {
		return mSize;
	}
	T& at(size_t index) throw(out_of_range) {
		if (index >= 0 && index < getSize())
			return mArray[index];
		else
			throw out_of_range("MyArray::at: Index out of range.");
	}
protected:
	size_t mSize;
	T* mArray;
};

inline void subParagraph_11_1_1() {
	cout << "Use of Templates" << endl;
	cout << "----------------" << endl;

	// Wrap an int array
	MyArray<int> arrInt(10);
	cout << "-> Array size: " << arrInt.getSize() << endl;
	arrInt.at(3) = 42;
	cout << "-> arr[3] = " << arrInt.at(3) << endl;
	try {
		arrInt.at(10) = 3;
	}
	catch (const exception& e) {
		cout << "-> Caught exception: '" << e.what() << "'" << endl;
	}
	// Wrap a std::string array
	MyArray<string> arrString(5);
	cout << "-> Array size: " << arrString.getSize() << endl;
	arrString.at(3) = "This  is a test";
	cout << "-> arr[3] = " << arrString.at(3) << endl;
	try {
		arrString.at(10) = 3;
	}
	catch (const exception & e) {
		cout << "-> Caught exception: '" << e.what() << "'" << endl;
	}
}