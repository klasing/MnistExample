#include "pch.h"

inline void subParagraph_14_1_2() {
	cout << "String Literals" << endl;
	cout << "---------------" << endl;

	// can't be done anymore
	//char* paChar = "hello";
	// can be done, uses literal pooling
	const char* paChar = "hello";
	cout << "-> " << paChar << endl;
	// alternative, no literal pooling, contents can be modified
	char aChar[] = "hello";
	aChar[0] = 'H';
	cout << "-> " << aChar << endl;
}