#include "pch.h"

#include <utility>
#include <tuple>
#include <typeinfo>
#include <functional>
#include <vector>

inline void example_16_5_a() {
	pair<int, string> p1(16, "Hello World");
	pair<bool, float> p2(true, 0.123);

	cout << "-> p1 = (" << p1.first << ", " << p1.second.c_str() << ")" << endl;
	cout << "-> p2 = (" << p2.first << ", " << p2.second << ")" << endl;
}

inline void example_16_5_bcde() {
	// b) create a tuple
	typedef tuple<int, string, bool> MyTuple;
	MyTuple t1(16, "Test", true);

	// c) get an element inside the tuple
	cout << "-> t1 = (" << get<0>(t1) << ", " << get<1>(t1).c_str() << ", "
		<< get<2>(t1) << ")" << endl;

	// d) get the type of an element inside the tuple
	cout << "-> Type of get<1>(t1) = " << typeid(get<1>(t1)).name() << endl;

	// e) get the size of a tuple, i.d. the number of element inside the tuple
	cout << "-> Tuple Size = " << tuple_size<MyTuple>::value << endl;
}

inline void example_16_5_fgh() {
	// f) use std::make_tuple() to create a tuple
	double d = 3.14;
	string str1 = "Test";
	auto t2 = make_tuple(16, ref(d), ref(str1), cref(str1));

	// g) show the double reference, which is the second element inside the tuple
	cout << "-> d = " << d << endl;
	get<1>(t2) *= 2;
	cout << "-> d = " << d << endl;

	// h) show the consequences of using the ref() and the cref() helpers
	cout << "-> str = " << str1.c_str() << endl;
	get<2>(t2) = "Hello";
	// ERROR: would be an error because of cref
	// get<3>(t2) = "Hello";
	cout << "-> str = " << str1.c_str() << endl;
}

inline void example_16_5_ijk() {
	// create a tuple which has a container as an element
	tuple<string, vector<int>> t0("test", { 1,2,3,4 });

	// i) use tie, to tie variables to elements inside a tuple
	tuple<int, string, bool> t1(16, "Test", true);
	int i = 0;
	string str;
	bool b = false;
	cout << "-> Before: i = " << i 
		<< ", str = \"" << str.c_str() << "\""
		<< ", b = " << b << endl;
	tie(i, str, b) = t1;
	cout << "-> After: i = " << i
		<< ", str = \"" << str.c_str() << "\""
		<< ", b = " << b << endl;

	// j) use std::tuple_cat() to concatenate two tuples into one (third) tuple
	tuple<int, string, bool> tOne(16, "Test", true);
	tuple<double, string> tTwo(3.14, "string 2");
	auto tThree = tuple_cat(tOne, tTwo);
	cout << "-> tuple one: " << get<0>(tOne) << ", " 
		<< get<1>(tOne).c_str() << ", " 
		<< get<2>(tOne) << endl;
	cout << "-> tuple two: " << get<0>(tTwo) << ", "
		<< get<1>(tTwo).c_str() << endl;
	cout << "-> tuple three: " << get<0>(tThree) << ", "
		<< get<1>(tThree).c_str() << ", "
		<< get<2>(tThree) << ", "
		<< get<3>(tThree) << ", " 
		<< get<4>(tThree).c_str() << endl;

	// k) show the usage of comparison operators for a tuple
	tuple<int, string> tk1(123, "def");
	tuple<int, string> tk2(123, "abc");
	cout << "-> tk1: " << get<0>(tk1) << ", " << get<1>(tk1).c_str() << endl;
	cout << "-> tk2: " << get<0>(tk2) << ", " << get<1>(tk2).c_str() << endl;
	if (tk1 < tk2)
		cout << "-> tk1 < tk2" << endl;
	else
		cout << "-> tk1 >= tk2" << endl;
}

inline void paragraph_16_5() {
	cout << "Tuples" << endl;
	cout << "------" << endl;

	example_16_5_a();
	example_16_5_bcde();
	example_16_5_fgh();
	example_16_5_ijk();
}