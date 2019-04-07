#include "pch.h"

#include <string>
#include <locale>
#include <codecvt>

inline void subParagraph_14_2_3() {
	cout << "Non-Western Character Sets" << endl;
	cout << "--------------------------" << endl;

	const char* s1 = u8R"(Raw UTF-8 encoded string literal)";
	cout << "-> " << s1 << endl;
	const wchar_t* s2 = LR"(Raw wide string literal)";
	wcout << "-> " << s2 << endl;

	//// https://gist.github.com/rednaxelafx/6605567
	// const char16_t* s3 = uR"(Raw char16_t string literal)";
	//u16string s3 = u"Raw char16_t string literal";
	////cout << "-> " << s3 << endl;
	//wstring_convert<codecvt_utf8<char16_t>, char16_t> cv;
	//cout << "-> " << cv.to_bytes(s3) << endl;
	//const char32_t* s4 = UR"(Raw char32_t string literal)";
	////cout << "-> " << s4 << endl;

	// https://stackoverflow.com/questions/32055357/visual-studio-c-2015-stdcodecvt-with-char16-t-or-char32-t
	//const char16_t* s3 = uR"(Raw char16_t string literal)";
	u16string s3 = u"Raw char16_t string literal";
	wstring wStr16(s3.begin(), s3.end());
	wstring_convert<codecvt_utf8_utf16<wchar_t>> cv16;
	cout << "-> " << cv16.to_bytes(wStr16) << endl;

	//const char32_t* s4 = UR"(Raw char32_t string literal)";
	u32string s4 = U"Raw char32_t string literal";
	wstring wStr32(s4.begin(), s4.end());
	wstring_convert<codecvt_utf8_utf16<wchar_t>> cv32;
	cout << "-> " << cv32.to_bytes(wStr32) << endl;

	// does not deliver the desired output
	const char* formula = u8"\u03C0 r\u00B2";
	cout << "-> " << formula << endl;
}
