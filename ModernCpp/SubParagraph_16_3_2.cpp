#include "pch.h"

#include <chrono>
#include <ratio>
#include <iomanip>

using namespace std::chrono;
inline void example_16_3_2_a() {
	// Get current time as a time_point
	system_clock::time_point tpoint = system_clock::now();

	// Convert to a time_t
	time_t tt = system_clock::to_time_t(tpoint);

	// Convert to local time
	tm* t = localtime(&tt);

	// Write the time to the console
	cout << "-> " << put_time(t, "%H:%M:%S") << endl;
}

inline void example_16_3_2_b() {
	// Get the start time
	auto start = system_clock::now();

	// Execute code that you want to time
	double d = 0;
	for (int i = 0; i < 1000000; ++i)
		d += sqrt(sin(i) * cos(i));

	// Get the end time and calculate the difference
	auto end = system_clock::now();
	auto diff = end - start;

	// Covert the difference into milliseconds and print on the console
	cout << "-> " << duration<double, milli>(diff).count() << "ms" << endl;
}

inline void subParagraph_16_3_2() {
	cout << "Clock" << endl;
	cout << "-----" << endl;

	example_16_3_2_a();
	example_16_3_2_b();
}