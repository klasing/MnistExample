#include "pch.h"

typedef bool(*YesNoFcn)(int, int);
// or C++1 style
using YesNoFcn = bool(*)(int, int);

inline void findMatches(int values1[], int values2[], size_t numValues, YesNoFcn inFunc) {
	for (size_t i = 0; i < numValues; i++)
		if (inFunc(values1[i], values2[i]))
			cout << "-> Match found at position " << i <<
			" (" << values1[i] << ", " << values2[i] << ")" << endl;
}

inline bool intEqual(int inItem1, int inItem2) {
	return inItem1 == inItem2;
}

inline bool bothOdd(int inItem1, int inItem2) {
	return inItem1 % 2 == 1 && inItem2 % 2 == 1;
}

inline void subParagraph_21_3_5() {
	cout << "Function Pointers" << endl;
	cout << "-----------------" << endl;

	int arr1[] = { 2, 5, 6, 9, 10, 1, 1 };
	int arr2[] = { 4, 4, 2, 9, 0, 3, 4 };
	int arrSize = sizeof(arr1) / sizeof(arr1[0]);
	cout << "-> Calling findMatches() using intEqual():" << endl;
	findMatches(arr1, arr2, arrSize, &intEqual);
	cout << "-> Calling findMatches() using bothOdd():" << endl;
	findMatches(arr1, arr2, arrSize, &bothOdd);

}
