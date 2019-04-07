#include "pch.h"

#include <locale>

inline void subParagraph_14_2_4() {
	cout << "Locales and Facets" << endl;
	cout << "------------------" << endl;

	cout << "a) Using Locales" << endl;
	// user's locale
	wcout.imbue(locale(""));
	wcout << "-> " << 32767 << endl;
	// default locale (classic C locale)
	wcout.imbue(locale("C"));
	wcout << "-> " << 32767 << endl;
	// U.S. English locale
	wcout.imbue(locale("en_US"));
	wcout << "-> " << 32767 << endl;
	locale loc("");
	if (loc.name().find("en_US") == string::npos &&
		loc.name().find("United States") == string::npos)
		wcout << "-> " << L"Welcome non-U.S. English speaker!" << endl;
	else
		wcout << "-> " << L"Welcome U.S. English speaker!" << endl;
	cout << "b) Using Facets" << endl;
	locale locUSEng("en_US");
	locale locBritEng("en_GB");
	wstring dollars = use_facet<moneypunct<wchar_t>>(locUSEng).curr_symbol();
	wstring pounds = use_facet<moneypunct<wchar_t>>(locBritEng).curr_symbol();
	wcout << L"-> In the US, the currency symbol is " << dollars << endl;
	// environment is not equipped to handle the British pound symbol
	wcout << L"-> In Great Britain, the currency symbol is " << pounds << endl;
}