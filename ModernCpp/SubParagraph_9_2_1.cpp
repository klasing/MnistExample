#include "pch.h"

inline void func_9_2_1(const int param) {
	// Not allowed to change param...
}

class BigClass_9_2_1 {};

inline void doSomething_9_2_1(const BigClass_9_2_1& arg) {
	// Implementation here
}

//const int getArraySize_9_2_1() { return 32; }
constexpr int getArraySize_9_2_1() { return 32; }

class Rect_9_2_1 {
public:
	constexpr Rect_9_2_1(int width, int height)
		: mWidth(width), mHeight(height) {}
	constexpr int getArea() const { return mWidth * mHeight; }
private:
	int mWidth, mHeight;
};

inline void subParagraph_9_2_1() {
	cout << "The const Keyword" << endl;
	cout << "-----------------" << endl;

	cout << "a) const Variables and Parameters" << endl;
	const double PI = 3.14159;
	cout << "b) const Pointers" << endl;
	//const int* ip;
	// or, semantically equivalent
	int const* ip; // protecting the variables
	ip = new int[10];
	// DOES NOT COMPILE
	//ip[4] = 5;
	int* const ip_ = nullptr; // protecting the pointer
	// DOES NOT COMPILE
	//ip_ = new int[10];
	// Error: dereferencing a null pointer
	//ip[4] = 5;
	// a const pointer has to be initialized when it is declared
	int* const ip__ = new int[10];
	// marking both value and pointer as const
	//int const* const ip_ex = nullptr;
	// or, semantically equivalent
	const int* const ip_ex = nullptr;
	// extend to any level of indirection
	const int* const* const* const ip_ex1 = nullptr;
	cout << "c) const References" << endl;
	int z;
	const int& zRef = z;
	// DOES NOT COMPILE
	//zRef = 4;
	cout << "d) const Methods" << endl;
	cout << "a) The constexpr Keyword (C++11)" << endl;
	// Invalid in C++
	// but, when the function is a constexpr
	// OK with C++11
	//int myArray[getArraySize_9_2_1()];
	// OK with C++11
	int myArray[getArraySize_9_2_1() + 1];
	constexpr Rect_9_2_1 r(8, 2);
	// OK with C++11
	int myArray_[r.getArea()];
}