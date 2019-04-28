#include "pch.h"

#include <complex>
#include <string>

inline complex<double> operator"" _i(long double d) {
	return complex<double>(0, d);
}

inline string operator"" _s(const char* str, size_t len) {
	return string(str, len);
}

inline void subParagraph_9_5_8() {
	cout << "User Defined Literals" << endl;
	cout << "---------------------" << endl;

	complex<double> c1 = 9.634_i;
	cout << "-> " << c1 << endl;
	// c2 will have as type std::complex<double>
	auto c2 = 1.23_i;

	string str1 = "Hello World"_s;
	// str2 will have as type std::string
	auto str2 = "Hello World"_s;
	cout << "-> " << str2 << endl;

	// the third example is not very clear to me
}
