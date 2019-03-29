#include "pch.h"

#include <atomic>

inline void example_22_2_2() {
	atomic<int> value(10);
	cout << "-> Value = " << value << endl;
	int fetched = value.fetch_add(4);
	cout << "-> Fetched = " << fetched << endl;
	cout << "-> Value = " << value << endl;
}

inline void subParagraph_22_2_2() {
	cout << "Atomic Operations" << endl;
	cout << "-----------------" << endl;

	example_22_2_2();
}