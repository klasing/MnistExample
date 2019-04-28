#include "pch.h"

#include <vector>

struct CircleStruct {
	int x, y;
	double radius;
};

class CircleClass {
public:
	CircleClass(int x, int y, double radius)
		: mX(x), mY(y), mRadius(radius), mArray{ 0,1,2,3 } {}
private:
	int mX, mY;
	double mRadius;
	// to be used for C++11 Uniform Initialization
	int mArray[4];
};

inline void func_9_5_1(int i) { /* ... */ }

inline void subParagraph_9_5_1() {
	cout << "Uniform Initialization" << endl;
	cout << "----------------------" << endl;

	// pre C++11 initialization
	CircleStruct myCircle1 = {10, 10, 2.5};
	CircleClass myCircle2(10, 10, 2.5);
	// C++11 Uniform Initialization
	CircleStruct myCircle3 = { 10, 10, 2.5 };
	CircleClass myCircle4 = { 10, 10, 2.5 };
	// or even shorter (better)
	CircleStruct myCircle3_{ 10, 10, 2.5 };
	CircleClass myCircle4_{ 10, 10, 2.5 };
	// Uniform Initialization prevents narrowing
	int x = 3.14;		// narrows down to x = 3
	func_9_5_1(3.14);	// narrows down to func_9_5_1(3);
	// Error because of narrowing
	//int x = { 3.14 };
	//func_9_5_1({ 3.14 });
	// pre C++11 vector initialization
	vector<string> myVec;
	myVec.push_back("String 1");
	myVec.push_back("String 2");
	myVec.push_back("String 3");
	// C++11 vector Uniform Initialization
	vector<string> myVec_ = { "String 1", "String 2", "String 3" };
	int* pArray = new int[4]{ 0,1,2,3 };

}