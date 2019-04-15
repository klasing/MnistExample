#include "pch.h"

#include <vector>
#include <numeric>
#include <functional>

inline bool allTrue(const vector<bool>& flags) {
	return accumulate(flags.begin(), flags.end(), true,
		logical_and<bool>());
}

inline bool anyTrue(const vector<bool>& flags) {
	return accumulate(flags.begin(), flags.end(), true,
		logical_or<bool>());
}

inline void subParagraph_13_3_3() {
	cout << "Logical Function Objects" << endl;
	cout << "------------------------" << endl;

	vector<bool> myVector = { 1, 0, 1 };
	if (allTrue(myVector))
		cout << "-> All true" << endl;
	else
		cout << "-> At least one false" << endl;
	if (anyTrue(myVector))
		cout << "-> At least one true" << endl;
	else
		cout << "-> All false" << endl;

}