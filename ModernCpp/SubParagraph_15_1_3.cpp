#include "pch.h"

#include <string>
#include <iomanip>

inline void rawwrite(const char* data, int dataSize) {
	cout << "-> ";
	cout.write(data, dataSize);
	cout << endl;
}

inline void rawPutchar(const char* data, int charIndex) {
	cout << "-> ";
	cout.put(data[charIndex]);
	cout << endl;
}

inline void subParagraph_15_1_3() {
	cout << "Output with Streams" << endl;
	cout << "-------------------" << endl;

	cout << "a) Output Basics" << endl;
	int i = 7;
	cout << "-> " << i << endl;
	char ch = 'a';
	cout << "-> " << ch << endl;
	string myString = "Marni is adorable.";
	cout << "-> " << myString << endl;
	int j = 11;
	cout << "-> On a scale of 1 to cute, Marni ranks " << j << endl;
	cout << "-> " << "Line 1" << endl
		<< "-> " << "Line 2" << endl
		<< "-> " << "Line 3" << endl;
	cout << "b) Methods of Output Streams" << endl;
	cout << "   b.1) put() and write()" << endl;
	const char* pszData = "This is data for the rawWrite() and the rawPutChar() functions.";
	rawwrite(pszData, strlen(pszData));
	// place the last character from the string onto the console
	rawPutchar(pszData, strlen(pszData) - 1);
	cout << "   b.2) flush()" << endl;
	cout << "-> abc";
	cout.flush();
	cout << "def";
	cout << endl;
	cout << "c) Handling Output Errors" << endl;
	// usefull methods:
	// check state       cout.good()
	// verify useability cout.fail()
	// reset error state cout.clear()
	cout.exceptions(ios::failbit | ios::badbit | ios::eofbit);
	try {
		cout << "-> Hello World." << endl;
	}
	catch (const ios_base::failure& ex) {
		cerr << "-> Caught exception: " << ex.what()
			<< ", error code = " << ex.code() << endl;
	}
	cout << "d) Output Manipulators" << endl;
	// Boolean values
	bool myBool = true;
	cout << "-> This is the default: " << myBool << endl;
	cout << "-> This should be true: " << boolalpha << myBool << endl;
	cout << "-> This should be 1: " << noboolalpha << myBool << endl;

	// Simulate "%6d" with streams
	int i_ = 123;
	printf("-> This should be '   123': %6d\n", i_);
	cout << "-> This should be '   123': " << setw(6) << i_ << endl;
	// Simulate "%06d" with streams
	printf("-> This should be '000123': %06d\n", i_);
	cout << "-> This should be '000123': " << setfill('0') << setw(6) << i_ << endl;

	// Fill with *
	cout << "-> This should be '***123': " << setfill('*') << setw(6) << i_ << endl;
	// Reset fill character
	cout << setfill(' ');

	// Floating point values
	double dbl = 1.452;
	double dbl2 = 5;
	cout << "-> This should be ' 5':  " << setw(2) << noshowpoint << dbl2 << endl;
	cout << "-> This should be @@1.452: " << setw(7) << setfill('@') << dbl << endl;

	// Format numbers according to your location
	cout.imbue(locale(""));
	cout << "-> This is 1234567 formatted according to your location: " << 1234567 << endl;

	// C++11 put_money
	cout << "-> This should be a money amount of 1200, "
		<< "formatted according to your location: "
		<< put_money("120000") << endl;

	// C++11 put_time
	time_t tt;
	time(&tt);
	tm t;
	localtime_s(&t, &tt);
	cout << "-> This should be the current date and time "
		<< "formatted according to your location: "
		<< put_time(&t, "%c") << endl;

	cout << "-> This should be '1.2346': " << setprecision(5) << 1.234567 << endl;
	cout.precision(5);
	cout << "-> This should be '1.2346': " << 1.23456789 << endl;
}

//#include "pch.h"
//
//#include <iomanip>
//
//inline void example_15_1_3_a() {
//	int i = 7;
//	cout << "-> " << i << endl;
//
//	char ch = 'a';
//	cout << "-> " << ch << endl;
//
//	string myString = "Marni is adorable.";
//	cout << "-> " << myString.c_str() << endl;
//}
//
//inline void example_15_1_3_b() {
//	int j = 11;
//
//	cout << "-> On a scale of 1 to cute, Marni ranks " << j << "!" << endl;
//}
//
//inline void example_15_1_3_c() {
//	cout << "-> Line 1" << endl << "-> Line 2" << endl << "-> Line 3" << endl;
//}
//
//inline void example_15_1_3_d(const char* data, int dataSize) {
//	cout << "-> ";
//	cout.write(data, dataSize);
//	cout << endl;
//}
//
//inline void example_15_1_3_e(const char* data, int charIndex) {
//	cout << "-> ";
//	cout.put(data[charIndex]);
//	cout << endl;
//}
//
//inline void example_15_1_3_f() {
//	cout << "-> abc";
//	cout.flush();
//	cout << endl;
//
//	cout << "-> def";
//	cout << endl;
//}
//
//inline void example_15_1_3_g() {
//	cout.exceptions(ios::failbit | ios::badbit | ios::eofbit);
//
//	try {
//		cout << "-> Hello World." << endl;
//	}
//	catch (const ios_base::failure& ex) {
//		cerr << "Caught exception: " << ex.what() << ", error code = " << ex.code() << endl;
//	}
//}
//
//inline void example_15_1_3_h() {
//	// Boolean values
//	bool myBool = true;
//	cout << "-> This is the default: " << myBool << endl;
//	cout << "-> This should be true: " << boolalpha << myBool << endl;
//	cout << "-> This should be 1: " << noboolalpha << myBool << endl;
//
//	// Simulate "%6d" with streams
//	int i = 123;
//	printf("-> This should be '   123': %6d\n", i);
//	cout << "-> This should be '   123': " << setw(6) << i << endl;
//	// Simulate "%06d" with streams
//	printf("-> This should be '000123': %06d\n", i);
//	cout << "-> This should be '000123': " << setfill('0') << setw(6) << i << endl;
//
//	// Fill with *
//	cout << "-> This should be '***123': " << setfill('*') << setw(6) << i << endl;
//	// Reset fill character
//	cout << setfill(' ');
//
//	// Floating point values
//	double dbl = 1.452;
//	double dbl2 = 5;
//	cout << "-> This should be ' 5': " << setw(2) << noshowpoint << dbl2 << endl;
//	cout << "-> This should be '@@1.452: " << setw(7) << setfill('@') << dbl << endl;
//
//	// Format numbers according to your location
//	cout.imbue(locale(""));
//	cout << "-> This is 1234567 formatted to your location: " << 1234567 << endl;
//
//	// C++11 put_money:
//	cout << "-> This should be a money amount of 1200, "
//		<< "formatted according to your location: "
//		<< put_money("120000") << endl;
//
//	// C++11 put_time
//	time_t tt;
//	time(&tt);
//	tm t;
//	localtime_s(&t, &tt);
//	cout << "-> This should be the current date and time "
//		<< "formatted according to your location: "
//		<< put_time(&t, "%c") << endl;
//
//	cout << "-> This should be '1.2346': " << setprecision(5) << 1.234567 << endl;
//	cout.precision(5);
//	cout << "-> This should be '1.2346': " << setprecision(5) << 1.23456789 << endl;
//}
//
//inline void subParagraph_15_1_3() {
//	cout << "Output with Streams" << endl;
//	cout << "-------------------" << endl;
//
//	cout << "Output Basics" << endl;
//	example_15_1_3_a();
//	example_15_1_3_b();
//	example_15_1_3_c();
//	cout << "Methods of Output Streams" << endl;
//	example_15_1_3_d("abcd", 4);
//	example_15_1_3_e("abcd", 0);
//	example_15_1_3_f();
//	cout << "Handling Output Errors" << endl;
//	example_15_1_3_g();
//	cout << "Output Manipulators" << endl;
//	example_15_1_3_h();
//}