#include "pch.h"

#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <cctype>

inline void func_(int num, const string& str) {
	cout << "-> func(" << num << ", " << str << ")" << endl;
}

inline void overloaded(int num) {}
inline void overloaded(float f) {}

inline void findEmtyString(const vector<string>& strings) {
	auto end = strings.end();
	auto it = find_if(strings.begin(), end, mem_fn(&string::empty));
	if (it == end)
		cout << "-> No empty strings!" << endl;
	else
		cout << "-> Empty string at position: " << it - strings.begin() << endl;
}

inline void findEmtyString(const vector<string*>& strings) {
	auto end = strings.end();
	auto it = find_if(strings.begin(), end, mem_fn(&string::empty));
	if (it == end)
		cout << "-> No empty strings!" << endl;
	else
		cout << "-> Empty string at position: " << it - strings.begin() << endl;
}

inline bool isNumber(const string& str) {
	auto end = str.end();
	//auto it = find_if(str.begin(), end, not1(ptr_fun(::isigit)));
	// ptr_fun is deprecated in C++11, so a lambda function is used instead
	//auto it = find_if(str.begin(), end, [](char c) { return !::isdigit(c); });
	// or even nicer
	auto it = find_if_not(str.begin(), end, ::isdigit);
	return (it == end);
}

inline void subParagraph_13_3_5() {
	cout << "Function Object Adapters" << endl;
	cout << "------------------------" << endl;

	string str = "abc";
	auto f1 = bind(func_, placeholders::_1, str);
	f1(16);

	auto f2 = bind(func_, placeholders::_2, placeholders::_1);
	f2("Test", 32);

	// ERROR
	//auto f3 = bind(overloaded, placeholders::_1);
	// OK
	auto f4 = bind((void(*)(float))overloaded, placeholders::_1);

	int num;
	vector<int> myVector;
	while (true) {
		cout << "Enter a test score to add (0 to stop): ";
		cin >> num;
		if (num == 0)
			break;
		myVector.push_back(num);
	}
	auto end = myVector.end();
	auto it = find_if(myVector.begin(), end, 
		bind(greater_equal<int>(), placeholders::_1, 100));
	if (it == end)
		cout << "No perfect scores " << num << endl;
	else
		cout << "Found a \"perfect\" score of " << *it << endl;

	cout << "a) Pre-C++11 bind2nd and bind1st" << endl;
	auto it_ = find_if(myVector.begin(), end,
		bind2nd(greater_equal<int>(), 100));
	if (it_ == end)
		cout << "No perfect scores " << num << endl;
	else
		cout << "Found a \"perfect\" score of " << *it_ << endl;

	cout << "b) Negators" << endl;
	//auto it_ex = find_if(myVector.begin(), end,
	//	not1(bind2nd(greater_equal<int>(), 100)));
	// more elegant using a lambda expression
	auto it_ex = find_if(myVector.begin(), end, [](int i) { return i < 100; });
	if (it_ex == end)
		cout << "No perfect scores " << num << endl;
	else
		cout << "Found a \"less-than-perfect\" score of " << *it_ex << endl;

	cout << "c) Calling Member Fuctions" << endl;
	vector<string> myVector_ = { "one", "two", "three", "" };
	findEmtyString(myVector_);

	vector<string*> myVector_ex(4);
	myVector_ex[0] = new string("one");
	myVector_ex[1] = new string("two");
	myVector_ex[2] = new string("three");
	myVector_ex[3] = new string("");
	findEmtyString(myVector_ex);

	cout << "d) Adapting Real Functions" << endl;
	string strNumber("12345");
	cout << "-> " << strNumber
		<< (isNumber(strNumber) ? " is a number" : " is not a number") << endl;
}