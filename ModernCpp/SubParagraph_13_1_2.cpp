#include "pch.h"

#include <numeric>
#include <vector>

inline double arithmeticMean(const vector<int>& nums) {
	double sum = accumulate(nums.begin(), nums.end(), 0);
	return sum / nums.size();
}

inline void example_13_1_2_a() {
	int num;
	vector<int> myVector;
	while (true) {
		cout << "Enter a number to add (0 to stop): ";
		cin >> num;
		if (num == 0)
			break;
		myVector.push_back(num);
	}
	cout << "-> arithmetic mean is: " << arithmeticMean(myVector) << endl;
}

inline int product(int num1, int num2) {
	return num1 * num2;
}

inline double geometricMean(const vector<int>& nums) {
	//double mult = accumulate(nums.begin(), nums.end(), 1, product);
	// or by using a lambda expression
	double mult = accumulate(nums.begin(), nums.end(), 1,
		[](int num1, int num2) { return num1 * num2; });
	return pow(mult, 1.0 / nums.size());
}

inline void example_13_1_2_b() {
	int num;
	vector<int> myVector;
	while (true) {
		cout << "Enter a number to add (0 to stop): ";
		cin >> num;
		if (num == 0)
			break;
		myVector.push_back(num);
	}
	cout << "-> geometric mean is: " << geometricMean(myVector) << endl;
}

inline void subParagraph_13_1_2() {
	cout << "The accumulate Algorithms" << endl;
	cout << "-------------------------" << endl;

	example_13_1_2_a();
	example_13_1_2_b();
}