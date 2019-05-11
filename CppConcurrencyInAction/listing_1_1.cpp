// Listing 1.1
// A simple Hello, Concurrent World program
#pragma once
#include <iostream>

using namespace std;
namespace ns_listing_1_1 {
	inline void hello() {
		cout << "-> [listing 1.1] Hello Concurrent World\n";
	}
}