#include "pch.h"

#include <ratio>

inline void example_16_2() {
	// Define a compile time rational number
	typedef ratio<1, 60> r1;
	cout << "-> 1) " << r1::num << " /" << r1::den << endl;

	// Get numerator and denominator
	intmax_t num = r1::num;
	intmax_t den = r1::den;
	cout << "-> 2) " << num << " /" << den << endl;

	// Add two ratiional numbers
	typedef ratio<1, 30> r2;
	cout << "-> 3) " << r2::num << " /" << r2::den << endl;
	typedef ratio_add<r1, r2>::type result;
	cout << "-> 4) " << result::num << " /" << result::den << endl;

	// Compare two rational numbers
	typedef ratio_less<r2, r1> res;
	cout << "-> 5) " << boolalpha << res::value << endl;
}

inline void paragraph_16_2() {
	cout << "Ratios" << endl;
	cout << "------" << endl;

	example_16_2();
}