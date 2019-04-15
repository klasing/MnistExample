#pragma once

#include <iostream>
#include <string>
#include <utility>

class MyClass_13_4_3 {
public:
	MyClass_13_4_3() {}
	// this constructor is not given in the text
	MyClass_13_4_3(const MyClass_13_4_3& obj) : mStr(obj.getString()) {}
	MyClass_13_4_3(const std::string& str) : mStr(str) {}
	// Move assignment operator
	MyClass_13_4_3& operator=(MyClass_13_4_3&& rhs) {
		if (this == &rhs)
			return *this;
		mStr = std::move(rhs.mStr);
		std::cout << "-> Move operator= (mStr=" << mStr << ")" << std::endl;
		return *this;
	}
	std::string getString() const { return mStr; }
protected:
	std::string mStr;
};
