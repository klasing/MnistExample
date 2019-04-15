#include "pch.h"

#include <numeric>
#include <vector>

inline double geometricMean_(const vector<int>& nums) {
	//double mult = accumulate(nums.begin(), nums.end(), 1, product);
	// or by using a lambda expression
	//double mult = accumulate(nums.begin(), nums.end(), 1,
	//	[](int num1, int num2) { return num1 * num2; });
	// now with a function object
	double mult = accumulate(nums.begin(), nums.end(), 1,
		multiplies<int>());
	return pow(mult, 1.0 / nums.size());
}

inline void subParagraph_13_3_1() {
	cout << "Arithmetic Fuction Objects" << endl;
	cout << "--------------------------" << endl;

	plus<int> myPlus;
	int res = myPlus(4, 5);
	cout << "-> 4 + 5 is " << res << endl;

	int num;
	vector<int> myVector;
	while (true) {
		cout << "Enter a number to add (0 to stop): ";
		cin >> num;
		if (num == 0)
			break;
		myVector.push_back(num);
	}
	cout << "-> geometric mean is: " << geometricMean_(myVector) << endl;
}