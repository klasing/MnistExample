#include "pch.h"

// helloworld.cpp
#include <iostream>

inline int helloWorld() {
	std::cout << "-> Hello World" << std::endl;
	return 0;
}

inline void subParagraph_1_1_1() {
	cout << "The Obligatory Hello World" << endl;
	cout << "--------------------------" << endl;

	helloWorld();

	cout << "a) Comments" << endl;
	cout << "b) Preprecessor Directives" << endl;
	cout << "c) The main() Function" << endl;
	cout << "d) I/O Streams" << endl;
}