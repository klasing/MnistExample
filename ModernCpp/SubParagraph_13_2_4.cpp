#include "pch.h"

#include <vector>
#include <functional>
#include <algorithm>

inline void testCallback(const vector<int>& vec,
	const function<bool(int)>& callback) {
	cout << "-> ";
	for (auto i : vec) {
		// Call callback. If it returns false, stop iteration.
		if (!callback(i))
			break;
		// Callback did not stop iteration, so print value
		cout << i << " ";
	}
	cout << endl;
}

inline void subParagraph_13_2_4() {
	cout << "Lambda Expressions as Parameters" << endl;
	cout << "--------------------------------" << endl;

	vector<int> vec(10);
	int index = 0;
	cout << "-> ";
	generate(vec.begin(), vec.end(), [&index] { return ++index; });
	for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
	cout << endl;
	testCallback(vec, [](int i) { return i < 6; });


}