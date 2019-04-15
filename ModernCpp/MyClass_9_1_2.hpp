#pragma once

class MyClass_9_1_2 {
public:
	MyClass_9_1_2(int& ref) : mRef(ref) {}
protected:
	int& mRef;
};