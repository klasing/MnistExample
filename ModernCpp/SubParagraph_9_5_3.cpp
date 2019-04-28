#include "pch.h"

inline void func_9_5_3(char* str) { cout << "char* version" << endl; }
inline void func_9_5_3(int i) { cout << "int version" << endl; }

inline void subParagraph_9_5_3() {
	cout << "Null Pointer Constant" << endl;
	cout << "---------------------" << endl;


	// because NULL equals 0, the int version of func() is called
	func_9_5_3(NULL);
	func_9_5_3((char*)NULL);
	func_9_5_3(nullptr);
}