#include "pch.h"

inline void subParagraph_9_3_2() {
	cout << "typedefs for Function Pointers" << endl;
	cout << "------------------------------" << endl;

	// library loading at run time (Win32)
	//HMODULE lib = ::LoadLibrary(_T("library_name"));
	//// prototyping MyFunc()
	//int __stdcall MyFunc(bool b, int n, const char* p);
	//// define typedef for MyFunc()
	//typedef int(__stdcall *MyFuncProc)(bool b, int n, const char* p);
	//// declare variable with the typedef
	//MyFuncProc MyProc = ::GetProcAddress(lib, "MyFunc");
	//// call the function
	//MyProc(true, 3, "Hello world");
}