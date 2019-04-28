#include "pch.h"

#include <initializer_list>

inline int makeSum(initializer_list<int> lst) {
	int total = 0;
	for (auto iter = lst.begin(); iter < lst.end(); ++iter)
		total += (*iter);
	return total;
}

inline void subParagraph_9_5_5() {
	cout << "Initializer Lists" << endl;
	cout << "-----------------" << endl;

	int a = makeSum({ 1,2,3 });
	int b = makeSum({ 10,20,30,40,50,60 });
	// invalid
	//int a = makeSum({ 1,2,3.0 });
}