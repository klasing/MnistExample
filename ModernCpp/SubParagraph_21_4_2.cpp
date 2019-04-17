#include "pch.h"

#include <memory>
#include <utility>

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

class Simple {
public:
	Simple() { mIntPtr = new int(); }
	~Simple() { delete mIntPtr; }
	void setIntPtr(int inInt) { *mIntPtr = inInt; }
protected:
	int* mIntPtr;
};

// ... definition of Simple not shown for brevity
inline shared_ptr<Simple> func() {
	auto ptr = make_shared<Simple>();
	return ptr;
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

	shared_ptr<Simple> mySmartPtr = func();

	unique_ptr<int> p1(new int(42));
	// Error: does not compile
	// unique_ptr<int> p2 = p1;
	unique_ptr<int> p3 = move(p1);
}