#include "pch.h"

#include <unordered_map>
#include <string>

inline void subParagraph_12_5_2() {
	cout << "unordered_map" << endl;
	cout << "-------------" << endl;

	unordered_map<int, string> m = {
		{1, "Item 1"},
		{2, "Item 2"},
		{3, "Item 3"},
		{4, "Item 4"}
	};
	for (auto& p : m)
		 cout << "-> " << p.first << " = " << p.second << endl;
}