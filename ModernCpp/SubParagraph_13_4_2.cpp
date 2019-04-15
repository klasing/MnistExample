#include "pch.h"

#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <numeric>
#include "SumAndProd.hpp"

template<typename Container>
inline void populateContainer(Container& cont) {
	int num;
	while (true) {
		cout << "-> Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0)
			break;
		cont.push_back(num);
	}
}

inline int main_13_4_2_a() {
	vector<int> myVector;
	list<int> myList;
	cout << "-> Populate the vector:" << endl;
	populateContainer(myVector);
	cout << "-> Populate the list:" << endl;
	populateContainer(myList);

	if (myList.size() < myVector.size()) {
		cout << "-> Sorry, the list is not long enough." << endl;
		return 1;
	}
	// compare the two containers
	if (equal(myVector.begin(), myVector.end(), myList.begin()))
		cout << "The two containers have equal elements" << endl;
	else {
		// If the containers were not equal, find out why not
		auto miss = mismatch(myVector.begin(), myVector.end(),
			myList.begin());
		cout << "The following initial elements are "
			<< "the same in the vector and the list:" << endl;
		for (auto i = myVector.begin(); i != miss.first; ++i)
			cout << *i << '\t';
		cout << endl;
	}
	// Now order them.
	if (lexicographical_compare(myVector.begin(), myVector.end(),
		myList.begin(), myList.end()))
		cout << "The vector is lexicographically first." << endl;
	else
		cout << "The list is lexicographically first." << endl;
	return 0;
}

inline void printPair(const pair<int, int>& elem) {
	cout << "-> " << elem.first << "->" << elem.second << endl;
}

inline int main_13_4_2_b() {
	vector<int> myVector;
	populateContainer(myVector);
	SumAndProd func;
	func = for_each(myVector.cbegin(), myVector.cend(), func);
	cout << "The sum is " << func.sum << endl;
	cout << "The product is " << func.prod << endl;
	return 0;
}

inline void subParagraph_13_4_2() {
	cout << "Non-Modifying Algorithms" << endl;
	cout << "------------------------" << endl;

	cout << "a) Search Algorithms" << endl;
	// The list of elements to be searched
	vector<int> myVector = { 5, 6, 9, 8, 8, 3 };
	auto begin = myVector.begin();
	auto end = myVector.end();
	// Find the min and max elements in the vector
	auto it = min_element(begin, end);
	auto it2 = max_element(begin, end);
	cout << "-> min is " << *it << " and max is " << *it2 << endl;
	// Find the first pair of matching consecutive elements
	it = adjacent_find(begin, end);
	if (it != end)
		cout << "-> Found two consecutive equal elements with value " << *it << endl;
	// Find the first of two values
	vector<int> targets = { 8, 9 };
	it = find_first_of(myVector.begin(), myVector.end(), targets.begin(), targets.end());
	if (it != end)
		cout << "-> Found one of 8 or 9: " << *it << endl;
	// Find the first subsequence
	vector<int> sub = { 8, 3 };
	it = search(myVector.begin(), myVector.end(), sub.begin(), sub.end());
	if (it != end)
		cout << "-> Found subsequence {8, 3} " << endl;
	else
		cout << "-> Unable to find subsequence {8, 3} " << endl;
	// Find the last subsequence (wich is the same as the first in this example
	it2 = find_end(myVector.begin(), myVector.end(), sub.begin(), sub.end());
	if (it != it2)
		cout << "-> Error: search and find_end found different subsequences "
		<< "even though there is only one match." << endl;
	// Find the first subsequence of two consecutive 8s
	it = search_n(myVector.begin(), myVector.end(), 2, 8);
	if (it != end)
		cout << "-> Found two consecutive 8s" << endl;
	else
		cout << "-> Unable to find two consecutive 8s" << endl;

	vector<int> vec = { 0, 0, 0, 1, 0, 2, 0 };
	auto cbegin = vec.cbegin();
	auto cend = vec.cend();
	// Find an element != 0
	auto it_ = find_if_not(cbegin, cend, [](int i) { return i == 0; });
	if (it_ == cend)
		cout << "-> No element found != 0" << endl;
	else
		cout << "-> Found element " << *it_ << " != 0" << endl;
	// Find min and max with 1 algorithm
	auto minmax = minmax_element(cbegin, cend);
	cout << "-> Min = " << *(minmax.first) << " and Max = " << *(minmax.second) << endl;
	// all_of()
	vector<int> vec2 = { 1, 1, 1, 1 };
	if (all_of(vec2.cbegin(), vec2.cend(), [](int i) { return i == 1; }))
		cout << "-> All elements are == 1" << endl;
	else
		cout << "-> Not all elements are == 1" << endl;
	// any_of()
	vector<int> vec3 = { 0, 0, 1, 0 };
	if (any_of(vec3.cbegin(), vec3.cend(), [](int i) { return i == 1; }))
		cout << "-> At least one element == 1" << endl;
	else
		cout << "-> No elements are == 1" << endl;
	// none_of()
	vector<int> vec4 = { 0, 0, 0, 0 };
	if (none_of(vec4.cbegin(), vec4.cend(), [](int i) { return i == 1; }))
		cout << "-> All elements are != 1" << endl;
	else
		cout << "-> Some elements are == 1" << endl;
	// partition point (output is not conform the documentation...)
	vector<int> vec5 = { 1, 1, 0, 4, 5, 6 };
	auto ppoint = partition_point(vec5.cbegin(), vec5.cend(),
		[](int i) { return i = 1; });
	cout << "-> Partition point at position " << (ppoint - vec5.cbegin()) << endl;

	cout << "b) Numerical Processing Algorithms" << endl;
	vector<int> v1 = { 1, 2, 3, 4 };
	vector<int> v2 = { 9, 8, 7, 6 };
	cout << "-> " << inner_product(v1.cbegin(), v1.cend(), v2.cbegin(), 0) << endl;

	cout << "c) Comparison Algorithms" << endl;
	main_13_4_2_a();

	cout << "d) Operational Algorithms" << endl;
	map<int, int> myMap = { {4, 40}, {5, 50}, {6, 60} };
	for_each(myMap.cbegin(), myMap.cend(), [](const pair<int, int>& p)
		{ cout << "-> " << p.first << "->" << p.second << endl; });
	// pre C++11 requires a separate function
	map<int, int> myMap_;
	myMap_.insert(make_pair(4, 40));
	myMap_.insert(make_pair(5, 50));
	myMap_.insert(make_pair(6, 60));
	for_each(myMap_.begin(), myMap_.end(), printPair);
	main_13_4_2_b();
	// The populateContainer() function is identical to  the one shown earlier
	// for comparison algorithms, so it is omitted here.
	vector<int> myVector_ex;
	populateContainer(myVector_ex);
	int sum = 0;
	int prod = 1;
	for_each(myVector_ex.cbegin(), myVector_ex.cend(),
		[&](int i) {
		sum += i;
		prod *= i;
	});
	cout << "The sum is " << sum << endl;
	cout << "The product is " << prod << endl;
}