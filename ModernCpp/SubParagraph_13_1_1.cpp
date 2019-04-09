#include "pch.h"

#include <vector>
#include <algorithm>

inline int main_13_1_1_a() {
	int num;
	vector<int> myVector;
	while (true) {
		cout << "Enter a number to add (0 to stop): ";
		cin >> num;
		if (num == 0)
			break;
		myVector.push_back(num);
	}
	while (true) {
		cout << "Enter a number to lookup (0 to stop): ";
		cin >> num;
		if (num == 0)
			break;
		auto end = myVector.end();
		auto it = find(myVector.begin(), end, num);
		if (it == end)
			cout << "Could not find " << num << endl;
		else
			cout << "Found " << *it << endl;
	}
	return 0;
}

inline bool perfectScore(int num) {
	return (num >= 100);
}

inline int main_13_1_1_b() {
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
	//auto it = find_if(myVector.begin(), end, perfectScore);
	// or by using a lambda expression
	auto it = find_if(myVector.begin(), end, [](int i) { return i >= 100; });
	if (it == end)
		cout << "No perfect scores " << num << endl;
	else
		cout << "Found a \"perfect\" score of " << *it << endl;
	return 0;
}

inline void subParagraph_13_1_1() {
	cout << "The find and find_if Algorithms" << endl;
	cout << "-------------------------------" << endl;

	main_13_1_1_a();
	main_13_1_1_b();
}