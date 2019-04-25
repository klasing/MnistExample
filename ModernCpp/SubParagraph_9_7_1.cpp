#include "pch.h"

#include <cstdio>
#include <cstdarg>

extern bool debug_9_7_1;
inline void debugOut(char* str, ...) {
	va_list ap;
	if (debug_9_7_1) {
		va_start(ap, str);
		vfprintf(stderr, str, ap);
		va_end(ap);
	}
}

inline void printInts(int num, ...) {
	int temp;
	va_list ap;
	cout << "-> ";
	va_start(ap, num);
	for (int i = 0; i < num; i++) {
		temp = va_arg(ap, int);
		cout << temp << " ";
	}
	va_end(ap);
	cout << endl;
}

inline void subParagraph_9_7_1() {
	cout << "Variable-Length Argument Lists" << endl;
	cout << "------------------------------" << endl;

	printf("-> int %d\n", 5);
	printf("-> String %s and int %d\n", "hello", 5);
	printf("-> Many ints: %d, %d, %d, %d, %d\n", 1, 2, 3, 4, 5);

	debug_9_7_1 = true;
	char aCh1[] = "-> int %d\n";
	debugOut(aCh1, 5);
	char aCh2[] = "-> String %s and int %d\n";
	debugOut(aCh2, "hello", 5);
	char aCh3[] = "-> Many ints: %d, %d, %d, %d, %d\n";
	debugOut(aCh3, 1, 2, 3, 4, 5);

	cout << "a) Accessing the Arguments" << endl;
	printInts(5, 5, 4, 3, 2, 1);
	cout << "b) Why you shouldn't Use C-Style Variable-Length Argument Lists" << endl;
}