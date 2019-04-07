#include "pch.h"

inline char* copyString_14_1_1(const char* inString) {
	// BUG! Off by one!
	//char* result = new char[strlen(inString)];
	char* result = new char[strlen(inString) + 1];
	strcpy(result, inString);
	return result;
}

inline char* appendString_14_1_1(const char* inStr1, const char* inStr2, 
	const char* inStr3) {
	char* result = new char[strlen(inStr1) + strlen(inStr2) +
		strlen(inStr3) + 1];
	strcpy(result, inStr1);
	strcat(result, inStr2);
	strcat(result, inStr3);
	return result;
}

inline void subParagraph_14_1_1() {
	cout << "C-Style Strings" << endl;
	cout << "---------------" << endl;

	char* paCopyString = copyString_14_1_1("String to be copied");
	cout << "-> " << paCopyString << endl;

	//char* paStr1 = new char[strlen("First string") + 1];
	//strcpy(paStr1, "First string");
	// does NOT work anymore: literal pooling
	//char* paStr1 = "First string";
	// what can be done: literal pooling
	const char* paStr1 = "First string";
	// what can be done, but without literal pooling
	// (contents can be modified)
	//char paStr1[] = "First string";
	char* paStr2 = new char[strlen(" second string") + 1];
	strcpy(paStr2, " second string");
	char* paStr3 = new char[strlen(" third string") + 1];
	strcpy(paStr3, " third string");
	char* paAppendString = appendString_14_1_1(paStr1, paStr2, paStr3);
	cout << "-> " << paAppendString << endl;

	// clean up
	delete[] paCopyString;
	paCopyString = nullptr;

	// use only with a 'new char[]' statement
	//delete[] paStr1;
	// array type 'char[13]' is not assignable
	//paStr1 = nullptr;
	delete[] paStr2;
	paStr2 = nullptr;
	delete[] paStr3;
	paStr3 = nullptr;
	delete[] paAppendString;
	paAppendString = nullptr;
}