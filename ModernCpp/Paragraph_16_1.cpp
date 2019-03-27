#include "pch.h"

#include <functional>
#include <vector>
#include <algorithm>

inline void func(int num, const string& str) {
	cout << "-> func(" << num << ", " << str.c_str() << ")" << endl;
}

inline bool isEven(int num) {
	return num % 2 == 0;
}

inline int main_16_1_a() {
	vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i);
	// f2 will be of type function<bool(int)>
	auto f2 = isEven;
	int cnt = count_if(vec.cbegin(), vec.cend(), f2);
	cout << "-> " << cnt << " even numbers" << endl;
	return 0;
}

inline void process(const vector<int>& vec, function<void(int)> f) {
	for (auto& i : vec)
		f(i);
}

inline void print(int num) {
	cout << num << " ";
}

inline int main_16_1_b() {
	vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i);
	cout << "-> ";
	process(vec, print);
	cout << endl;

	int sum = 0;
	process(vec, [&sum](int num) {sum += num; });
	cout << "-> sum = " << sum << endl;
	
	return 0;
	cout << endl;
}

inline void paragraph_16_1() {
	cout << "std::function" << endl;
	cout << "-------------" << endl;

	//function<void(int, const string&)> f1 = func;
	// or, much shorter
	auto f1 = func;
	f1(1, "test");

	main_16_1_a();
	main_16_1_b();
}