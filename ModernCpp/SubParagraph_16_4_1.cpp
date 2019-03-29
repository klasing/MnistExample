#include "pch.h"

#include <random>

inline void example_16_4_1() {
	random_device rnd;

	cout << "-> Entropy: " << rnd.entropy() << endl;
	cout << "-> Min value: " << rnd.min()
		<< ", Max value: " << rnd.max() << endl;
	cout << "-> Random number: " << rnd() << endl;
}

inline void subParagraph_16_4_1() {
	cout << "Random Number Engines" << endl;
	cout << "---------------------" << endl;

	example_16_4_1();
}