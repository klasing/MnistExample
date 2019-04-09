#include "pch.h"

#include <numeric>
#include <vector>

inline double arithmeticMean(const vector<int>& nums) {
	double sum = accumulate(nums.begin(), nums.end(), 0);
	return sum / nums.size();
}

inline int product(int num1, int num2) {
	return num1 * num2;
}

inline void subParagraph_13_1_2() {
	cout << "The accumulate Algorithms" << endl;
	cout << "-------------------------" << endl;
}