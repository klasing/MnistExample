#include "pch.h"

#include <vector>
#include <algorithm>

inline void subParagraph_13_2_5() {
	cout << "Examples" << endl;
	cout << "--------" << endl;

	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int value = 3;
	int cnt = count_if(vec.cbegin(), vec.cend(),
		[=](int i) { return i > value; });
	cout << "-> Found " << cnt << " values > " << value << endl;

	vector<int> vec_ = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int value_ = 3;
	int cntLambdaCalled = 0;
	int cnt_ = count_if(vec_.cbegin(), vec_.cend(),
		[=, &cntLambdaCalled](int i) { ++cntLambdaCalled; return i > value_; });
	cout << "-> The lambda expression was called " << cntLambdaCalled
		<< " times." << endl;
	cout << "-> Found " << cnt_ << " values > " << value_ << endl;

	vector<int> vec_ex(10);
	int value_ex = 1;
	generate(vec_ex.begin(), vec_ex.end(), [&value_ex] { value_ex *= 2; return value_ex; });
	cout << "-> ";
	for (auto& i : vec_ex)
		cout << i << " ";
	cout << endl;

	vector<int> vec__ = { 11, 22, 33, 44 };
	int index = 0;
	for_each(vec__.begin(), vec__.end(),
		[&index](int i) { cout << "-> Value " << (index++)
		<< ": " << i << endl; });
}