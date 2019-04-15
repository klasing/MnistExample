#include "pch.h"

#include <vector>
#include <algorithm>
#include <numeric>
#include "MyClass_13_4_3.hpp"

template<typename Container>
inline void populateContainer_(Container& cont) {
	int num;
	while (true) {
		cout << "-> Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0)
			break;
		cont.push_back(num);
	}
}

inline void removeEmptyStrings(vector<string>& strings) {
	auto it = remove_if(strings.begin(), strings.end(),
		[](const string& str) { return str.empty(); });
	// Erase the removed elelements
	strings.erase(it, strings.end());
}

inline void subParagraph_13_4_3() {
	cout << "Modifying Algorithms" << endl;
	cout << "--------------------" << endl;

	cout << "a) iota (C++11)" << endl;
	vector<int> vec(10);
	iota(vec.begin(), vec.end(), 5);
	cout << "-> ";
	for (auto& i : vec) cout << i << " ";
	cout << endl;
	cout << "b) transform" << endl;
	// The populateContainer() function is identical to the one shown earlier
	// for comparison algorithms, so it is omitted here.
	vector<int> myVector;
	populateContainer_(myVector);
	cout << "-> The vector contents are: " << endl;
	cout << "-> ";
	for (auto& i : myVector) cout << i << " ";
	cout << endl;
	transform(myVector.begin(), myVector.end(), myVector.begin(),
		[](int i) { return i + 100; });
	cout << "-> The vector contents are: " << endl;
	cout << "-> ";
	for (auto& i : myVector) cout << i << " ";
	cout << endl;
	// The populateContainer() function is identical to the one shown earlier
	// for comparison algorithms, so it is omitted here.
	vector<int> vec1;
	cout << "-> Vector1:" << endl;
	populateContainer_(vec1);
	vector<int> vec2;
	cout << "-> Vector2:" << endl;
	populateContainer_(vec2);
	// Create a lambda to print a vector
	auto printVec = [](const vector<int>& vec) {
		cout << "-> ";
		for (auto& i : vec) cout << i << " ";
		cout << endl;
	};
	if (vec2.size() < vec1.size()) {
		cout << "-> Vector2 should be at least the same size as vector1." << endl;
		goto skip;
	}
	// Create a lambda to print a vector
	//auto printVec = [](const vector<int>& vec) {
	//	cout << "-> ";
	//	for (auto& i : vec) cout << i << " ";
	//	cout << endl;
	//};
	cout << "-> Vector1: "; printVec(vec1);
	cout << "-> Vector2: "; printVec(vec2);
	transform(vec1.begin(), vec1.end(),
		vec2.begin(), vec1.begin(),
		[](int a, int b) { return a + b; });
	cout << "-> Vector1: "; printVec(vec1);
	cout << "-> Vector2: "; printVec(vec2);
skip:

	cout << "c) copy" << endl;
	// The populateContainer() function is identical to the one shown earlier
	// for comparison algorithms, so it is omitted here.
	vector<int> vec1_, vec2_;
	populateContainer_(vec1_);
	vec2_.resize(vec1_.size());
	//copy(vec1_.cbegin(), vec1_.cend(), vec2_.begin());
	// or, by using the copy backward() function, to get the same result as copy()
	copy_backward(vec1_.cbegin(), vec1_.cend(), vec2_.end());
	cout << "-> ";
	for_each(vec2_.cbegin(), vec2_.cend(), [](int i) { cout << i << " "; });
	cout << endl;
	// The populateContainer() function is identical to the one shown earlier
	// for comparison algorithms, so it is omitted here.
	vector<int> vec1_ex, vec2_ex;
	populateContainer_(vec1_ex);
	vec2_ex.resize(vec1_ex.size());
	auto endIterator = copy_if(vec1_ex.cbegin(), vec1_ex.cend(),
		vec2_ex.begin(), [](int i) { return i % 2 == 0; });
	vec2_ex.erase(endIterator, vec2_ex.end());
	cout << "-> ";
	for_each(vec2_ex.cbegin(), vec2_ex.cend(), [](int i) { cout << i << " "; });
	cout << endl;
	// The populateContainer() function is identical to the one shown earlier
	// for comparison algorithms, so it is omitted here.
	vector<int> vec1__, vec2__;
	populateContainer_(vec1__);
	size_t cnt = 0;
	cout << "-> Enter the number of elements you want to copy: ";
	cin >> cnt;
	cnt = min(cnt, vec1__.size());
	vec2__.resize(cnt);
	copy_n(vec1__.cbegin(), cnt, vec2__.begin());
	cout << "-> ";
	for_each(vec2__.cbegin(), vec2__.cend(), [](int i) { cout << i << " "; });
	cout << endl;
	// The populateContainer() function is identical to the one shown earlier
	// for comparison algorithms, so it is omitted here.
	vector<int> vec1__ex, vecOdd, vecEven;
	populateContainer_(vec1__ex);
	vecOdd.resize(vec1__ex.size());
	vecEven.resize(vec1__ex.size());

	auto pairIters = partition_copy(vec1__ex.cbegin(), vec1__ex.cend(),
		vecEven.begin(), vecOdd.begin(),
		[](int i) { return i % 2 == 0; });

	vecEven.erase(pairIters.first, vecEven.end());
	vecOdd.erase(pairIters.second, vecOdd.end());
	cout << "-> Even numbers: ";
	for_each(vecEven.cbegin(), vecEven.cend(), [](int i) { cout << i << " "; });
	cout << endl;
	cout << "-> Odd numbers: ";
	//for_each(vecOdd.cbegin(), vecOdd.cend(), [](int i) { cout << i << " "; });
	// can also be written as
	for (auto& i : vecOdd)
		cout << i << " ";
	cout << endl;

	cout << "d) move (C++11)" << endl;
	vector<MyClass_13_4_3> vecSrc = { MyClass_13_4_3("a"), MyClass_13_4_3("b"), MyClass_13_4_3("c") };
	vector<MyClass_13_4_3> vecDst(vecSrc.size());
	move(vecSrc.begin(), vecSrc.end(), vecDst.begin());
	cout << "-> ";
	for (auto& c : vecDst) cout << c.getString() << " ";
	cout << endl;

	cout << "e) replace" << endl;
	// The populateContainer() function is identical to the one shown earlier
	// for comparison algorithms, so it is omitted here.
	vector<int> vec1_1;
	populateContainer_(vec1_1);
	int lowLim = numeric_limits<short>::min(); // -32768
	int upLim = numeric_limits<short>::max();  // +32767
	replace_if(vec1_1.begin(), vec1_1.end(), [=](int i) { return i < lowLim; }, lowLim);
	replace_if(vec1_1.begin(), vec1_1.end(), [=](int i) { return i > upLim; }, upLim);
	cout << "-> ";
	for_each(vec1_1.cbegin(), vec1_1.cend(), [](int i) { cout << i << " "; });
	cout << endl;

	cout << "f) remove" << endl;
	vector<string> myVector_ = { "", "one", "", "two", "three", "four" };
	cout << "-> ";
	for (auto& str : myVector_) cout << "\"" << str << "\" ";
	cout << endl;
	removeEmptyStrings(myVector_);
	cout << "-> ";
	for (auto& str : myVector_) cout << "\"" << str << "\" ";
	cout << endl;

	cout << "g) unique" << endl;
	cout << "h) reverse" << endl;
	cout << "i) Other Modifying Algorithms" << endl;
}