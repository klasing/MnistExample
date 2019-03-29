#include "pch.h"

#include <ctime>
#include <random>
#include <functional>

inline void example_16_4_4_a() {
	mt19937 eng(static_cast<unsigned long>(time(nullptr)));
	uniform_int_distribution<int> dist(1, 99);
	auto gen = std::bind(dist, eng);
	vector<int> vec(10);
	generate(vec.begin(), vec.end(), gen);
	cout << "-> ";
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
}

template<class T>
inline void fillVector(vector<int>& vec, T rndGen) {
	generate(vec.begin(), vec.end(), rndGen);
}

inline void example_16_4_4_b() {
	mt19937 eng(static_cast<unsigned long>(time(nullptr)));
	uniform_int_distribution<int> dist(1, 99);
	auto gen = std::bind(dist, eng);
	vector<int> vec(10);
	fillVector(vec, gen);
	cout << "-> ";
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
}

inline void subParagraph_16_4_4() {
	cout << "Generating Random Numbers" << endl;
	cout << "-------------------------" << endl;

	example_16_4_4_a();
	example_16_4_4_b();
}