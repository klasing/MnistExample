#include "pch.h"

#include <ctime>
#include <random>
#include <functional>
#include <map>
#include <fstream>

inline void example_16_4_5_a() {
	const unsigned int DIST_START = 1;
	const unsigned int DIST_END = 99;
	const unsigned int ITERATIONS = 1000000;

	// Uniform Mersenne Twister
	mt19937 eng(static_cast<unsigned long>(time(nullptr)));
	uniform_int_distribution<int> dist(DIST_START, DIST_END);
	auto gen = bind(dist, eng);

	cout << "-> Please be patient." << endl;

	map<int, int> m;
	for (unsigned int i = 0; i < ITERATIONS; ++i) {
		int rnd = gen();
		// Search map for a key = rnd. If found, add 1 to the value associated
		// with that key. If not found, add the key to the map with value 1.
		++(m[rnd]);
	}

	// Write to a CSV file
	ofstream of("res.csv");
	for (unsigned int i = DIST_START; i <= DIST_END; ++i) {
		//of << i << ",";
		auto res = m.find(i);
		of << (res != m.end() ? res->second : 0) << endl;
	}
}

inline void example_16_4_5_b() {
	const unsigned int DIST_START = 1;
	const unsigned int DIST_END = 99;
	const unsigned int ITERATIONS = 1000000;

	// Uniform Mersenne Twister
	mt19937 eng(static_cast<unsigned long>(time(nullptr)));
	normal_distribution<double> dist(50, 10);
	auto gen = bind(dist, eng);

	cout << "-> Please be patient." << endl;

	map<int, int> m;
	for (unsigned int i = 0; i < ITERATIONS; ++i) {
		int rnd = static_cast<int>(gen());
		// Search map for a key = rnd. If found, add 1 to the value associated
		// with that key. If not found, add the key to the map with value 1.
		++(m[rnd]);
	}

	// Write to a CSV file
	ofstream of("res_1.csv");
	for (unsigned int i = DIST_START; i <= DIST_END; ++i) {
		//of << i << ",";
		auto res = m.find(i);
		of << (res != m.end() ? res->second : 0) << endl;
	}
}

inline void subParagraph_16_4_5() {
	cout << "Random Number Distributions" << endl;
	cout << "---------------------------" << endl;

	example_16_4_5_a();
	// in Excel: selecteer de data in de kolom A (Ctrl+A),
	// klik op : invoegen -> grafieken -> lijn 
	//           -> eerste pictogram onder de Kop 2D-lijn
	example_16_4_5_b();
}