#include "pch.h"
//#include "pch.h"
//
//#include "GetMenuChoice.cpp"
//
////****************************************************************************
////*                     fillVector
////****************************************************************************
//template<class T>
//void fillVector(vector<int>& vec, T rndGen) {
//	 generate(vec.begin(), vec.end(), rndGen);
//}
//
////****************************************************************************
////*                     randomNumberGeneration
////****************************************************************************
//// function must be inline
//inline void randomNumberGeneration() {
//	OutputDebugString(L"randomNumberGeneration()\n");
//
//	bool bProceed = true;
//
//	// show the menu until the user terminates
//	while (bProceed) {
//		cout << "Random number generation" << endl;
//		cout << "========================" << endl;
//		cout << " 1) Random number engines" << endl;
//		cout << " 2) Random number engine adapters" << endl;
//		cout << " 3) Predefined engines and engine adapters" << endl;
//		cout << " 4) Generating random numbers" << endl;
//		cout << " 5) Random number distributions" << endl;
//		cout << "Enter the number of a part, or enter a zero to return to the upper menu: ";
//
//		int iMenuChoice = getMenuChoice();
//
//		switch (iMenuChoice) {
//		case 1: {
//			cout << "Random number engines" << endl;
//			cout << "=====================" << endl;
//
//			random_device rnd;
//			cout << "Entropy: " << rnd.entropy() << endl;
//			cout << "Min value: " << rnd.min << ", Max value: " << rnd.max << endl;
//			cout << "Random number: " << rnd() << endl;
//
//			break;
//		} // eof case 1
//		case 2:
//			cout << "Random number engine adapters" << endl;
//			cout << "=============================" << endl;
//
//
//			break;
//		case 3:
//			cout << "Predefined engines and engine adapters" << endl;
//			cout << "======================================" << endl;
//
//			break;
//		case 4: {
//			cout << "Generating random numbers" << endl;
//			cout << "=========================" << endl;
//
//			// predefined engine
//			mt19937 eng(static_cast<unsigned long>(time(nullptr)));
//			// define a distribution
//			uniform_int_distribution<int>  dist(1, 99);
//			// bind the engine to the distribution
//			auto gen = bind(dist, eng);
//			// generate random number
//			vector<int> vec(10);
//			// use a function to do the generation of random number
//			fillVector(vec, gen);
//			cout << "Random number: ";
//			for (auto i : vec)
//				cout << i << " ";
//			cout << endl;
//
//			break;
//		} // eof case 4
//		case 5: {
//			cout << "Random number distributions" << endl;
//			cout << "===========================" << endl;
//
//			cout << " a) Uniform distributions" << endl;
//			cout << " b) Bernouilli distributions" << endl;
//			cout << " c) Poisson distributions" << endl;
//			cout << " d) Normal distributions" << endl;
//			cout << " e) Sampling distributions" << endl;
//
//			// the next piece of code will take a while, 
//			// inform the user about this
//			cout << "Please, be patient." << endl;
//
//			// store random number in a CSV file
//			const unsigned int DIST_START = 1;
//			const unsigned int DIST_END = 99;
//			const unsigned int ITERATIONS = static_cast<unsigned int>(1e6);
//			// uniform Mersenne twister
//			mt19937 eng(static_cast<unsigned long>(time(nullptr)));
//			// first distribution type
//			//uniform_int_distribution<int> dist(DIST_START, DIST_END);
//			// alternative distribution type
//			normal_distribution<double> dist(50, 10);
//			auto gen = bind(dist, eng);
//
//			map<int, int> m;
//			for (unsigned int i = 0; i < ITERATIONS; ++i) {
//				// for first distribution type
//				//int rnd = gen();
//				// use for alternative distribution type
//				int rnd = static_cast<int>(gen());
//				// search map for a key = rnd
//				// if found, add 1 to the value associated with that key
//				// if not found, add the key to the map with value 1
//				++(m[rnd]);
//			}
//			// write to a CSV file
//			ofstream of("./res.csv");
//			for (unsigned int i = DIST_START; i <= DIST_END; ++i) {
//				// no need to store the x-axe value
//				//of << i << ", ";
//				auto res = m.find(i);
//				of << (res != m.end() ? res->second : 0) << endl;
//			}
//
//			break;
//		} // eof case 5
//		case 0:
//			// the user wants to terminate the program
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			cout << "The entered number is not recognized, please try again." << endl;
//		} // eof switch
//		cout << endl;
//	}
//}