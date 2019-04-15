#include "pch.h"

#include <vector>
#include <algorithm>

template<typename Container>
inline void populateContainer_ex(Container& cont) {
	int num;
	while (true) {
		cout << "-> Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0)
			break;
		cont.push_back(num);
	}
}

inline void subParagraph_13_4_4() {
	cout << "Sorting Algorithms" << endl;
	cout << "------------------" << endl;

	cout << "a) Basic Sorting and merging" << endl;
	// The populateContainer() function is identical to the one shown earlier
	// for comparison algorithms, so it is omitted here.
	vector<int> vectorOne, vectorTwo, vectorMerged;
	cout << "-> Enter values for the first vector: " << endl;
	populateContainer_ex(vectorOne);
	cout << "-> Enter values for the second vector: " << endl;
	populateContainer_ex(vectorTwo);
	// Sort both containers
	sort(vectorOne.begin(), vectorOne.end());
	sort(vectorTwo.begin(), vectorTwo.end());
	// Make sure the destination vector is large enough to hold the values
	// from both the source vectors.
	vectorMerged.resize(vectorOne.size() + vectorTwo.size());
	merge(vectorOne.cbegin(), vectorOne.cend(), vectorTwo.cbegin(),
		vectorTwo.cend(), vectorMerged.begin());
	cout << "-> Merged vector: ";
	for_each(vectorMerged.cbegin(), vectorMerged.cend(),
		[](int i) { cout << i << " "; });
	cout << endl;
	while (true) {
		int num;
		cout << "-> Enter a number to find (0 to quit): ";
		cin >> num;
		if (num == 0)
			break;
		if (binary_search(vectorMerged.cbegin(), vectorMerged.cend(), num))
			cout << "-> That number is in the vector." << endl;
		else
			cout << "-> That number is not in the vector." << endl;
	}

	cout << "b) Other Soritng Algorithms" << endl;
	cout << "c) Random Shuffle" << endl;
}