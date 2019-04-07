#include "pch.h"

#include <string>

inline void subParagraph_14_2_2() {
	cout << "Wide Characters" << endl;
	cout << "---------------" << endl;

	const wchar_t* pszWideChar = L"Wide Characters";
	wcout << L"-> " << pszWideChar << endl;
	wstring wStr = L"Wide String";
	wcout << L"-> " << wStr << endl;
}