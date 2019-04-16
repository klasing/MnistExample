#include "pch.h"

#include <memory>

inline int* malloc_int(int value) {
	int* p = (int*)malloc(sizeof(int));
	*p = value;
	return p;
}

inline void CloseFile(FILE* filePtr) {
	if (filePtr == nullptr)
		return;
	fclose(filePtr);
	cout << "-> File closed." << endl;
}

inline void subParagraph_21_4_2() {
	cout << "The new C++11 Smart Pointers" << endl;
	cout << "----------------------------" << endl;

	shared_ptr<int> myIntSmartPtr(malloc_int(42), free);

	shared_ptr<FILE> filePtr(fopen("data.tx", "w"), CloseFile);
	if (filePtr == nullptr)
		cerr << "-> Error opening file." << endl;
	else {
		cout << "-> File opened." << endl;
		// Use filePtr ...
	}
}