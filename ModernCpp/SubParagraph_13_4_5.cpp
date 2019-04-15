#include "pch.h"

#include <vector>
#include <algorithm>

template<typename Container>
inline void populateContainer__(Container& cont) {
	int num;
	while (true) {
		cout << "-> Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0)
			break;
		cont.push_back(num);
	}
}

inline void subParagraph_13_4_5() {
	cout << "Set Algorithms" << endl;
	cout << "--------------" << endl;

	// The populateContainer() function is identical to the one shown earlier
	// for comparison algorithms, so it is omitted here.
	vector<int> vec1, vec2, result;
	cout << "-> Enter elements for set 1: " << endl;
	populateContainer__(vec1);
	cout << "-> Enter elements for set 2: " << endl;
	populateContainer__(vec2);
	// set algorithms work on sorted ranges
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

}