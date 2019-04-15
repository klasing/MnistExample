#include "pch.h"

#include <vector>

inline void separateOddsAndEvens(const int arr[], int size, int** odds,
	int* numOdds, int** evens, int* numEvens) {
	// First pass to determine array sizes
	*numOdds = *numEvens = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 == 1)
			(*numOdds)++;
		else
			(*numEvens)++;
	// Allocate two new numbers of the appropriate size.
	*odds = new int[*numOdds];
	*evens = new int[*numEvens];
	// Copy the odds and evens to the new arrays
	int oddsPos = 0, evensPos = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 == 1)
			(*odds)[oddsPos++] = arr[i];
		else
			(*evens)[evensPos++] = arr[i];
}

inline void separateOddsAndEvens(const int arr[], int size, int*& odds,
	int& numOdds, int*& evens, int& numEvens) {
	// First pass to determine array sizes
	numOdds = numEvens = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 == 1)
			numOdds++;
		else
			numEvens++;
	// Allocate two new numbers of the appropriate size.
	odds = new int[numOdds];
	evens = new int[numEvens];
	// Copy the odds and evens to the new arrays
	int oddsPos = 0, evensPos = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 == 1)
			odds[oddsPos++] = arr[i];
		else
			evens[evensPos++] = arr[i];
}

inline void separateOddsAndEvens(const vector<int>& arr,
	vector<int>& odds, vector<int>& evens) {
	for (auto& i : arr)
		if (i % 2 == 1)
			odds.push_back(i);
		else
			evens.push_back(i);
}

inline void subParagraph_9_1_5() {
	cout << "Deciding between References and Pointers" << endl;
	cout << "----------------------------------------" << endl;

	int unSplit[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *oddNums, *evenNums;
	int numOdds, numEvens;
	separateOddsAndEvens(unSplit, 10, &oddNums, &numOdds, &evenNums, &numEvens);
	// clean up
	delete oddNums; oddNums = nullptr;
	delete evenNums; evenNums = nullptr;

	int unSplit_[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *oddNums_, *evenNums_;
	int numOdds_, numEvens_;
	separateOddsAndEvens(unSplit_, 10, oddNums_, numOdds_, evenNums_, numEvens_);
	// clean up
	delete oddNums_; oddNums_ = nullptr;
	delete evenNums_; evenNums_ = nullptr;

	vector<int> vecUnSplit = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> odds, evens;
	separateOddsAndEvens(vecUnSplit, odds, evens);
}