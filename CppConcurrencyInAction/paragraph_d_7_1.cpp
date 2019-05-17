#include <iostream>
#include <thread>

//#include "example_d_7_1_b.cpp"
#include "example_d_7_1_c.cpp"
#include "example_d_7_1_d.cpp"

using namespace std;
inline void paragraph_d_7_1() {
	cout << "D.7.1 std::thread class" << endl;
	cout << "-----------------------" << endl;

	cout << "a) swap()" << endl;
	cout << "b) joinable()" << endl;
	//using namespace ns_d_7_1_b;
	//example_d_7_1_b();

	cout << "c) join()" << endl;
	using namespace ns_d_7_1_c;
	example_d_7_1_c();

	cout << "d) detach()" << endl;
	using namespace ns_d_7_1_d;
	example_d_7_1_d();

	cout << "e) get_id()" << endl;
	// see paragraph_d_7_2

	cout << "f) hardware_concurrency()" << endl;
	unsigned int n = std::thread::hardware_concurrency();
	cout << "-> " << n << " concurrent threads are supported.\n";
}