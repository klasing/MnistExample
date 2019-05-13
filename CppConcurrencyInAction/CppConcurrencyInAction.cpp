#include <iostream>
#include <thread>

//#include "part1.cpp"
#include "listing_1_1.cpp"
#include "listing_2_1.cpp"
#include "listing_2_2.cpp"
#include "listing_2_3.cpp"
#include "listing_2_4.cpp"
#include "listing_2_5.cpp"
#include "listing_2_6.cpp"
#include "listing_2_7.cpp"
#include "listing_2_8.cpp"
#include "listing_3_1.cpp"

using namespace std;
// used in listing_3_1.cpp
namespace ns_listing_3_1 {
	list<int> some_list;
	mutex some_mutex;
}

int main() {
	using namespace ns_listing_1_1;
	thread t(hello);
	t.join();
	using namespace ns_listing_2_1;
	oops();
	using namespace ns_listing_2_2;
	try {
		f();
	}
	catch (...) {
		cout << "-> [main] exception catched" << endl;
	}
	using namespace ns_listing_2_3;
	try {
		ns_listing_2_3::f();
	}
	catch (...) {
		cout << "-> [main] exception catched" << endl;
	}
	using namespace ns_listing_2_4;
	// the functional behaviour in this example, is not like it should be
	edit_document("first file name");
	using namespace ns_listing_2_5;
	thread t1(ns_listing_2_5::f());
	thread t2(ns_listing_2_5::g());
	t1.join();
	t2.join();
	using namespace ns_listing_2_6;
	ns_listing_2_6::f();
	using namespace ns_listing_2_7;
	ns_listing_2_7::f();
	using namespace ns_listing_2_8;
	ns_listing_2_8::f();
	using namespace ns_listing_3_1;
}
//	bool bProceed = true;
//	unsigned iChar = 0;
//
//	while (bProceed) {
//		cout << "C++ Concurency In Action" << endl;
//		cout << "========================" << endl;
//		cout << " 1) Hello, world of concurrency in C++!" << endl;
//		cout << "Enter the number of a subject, or enter a zero to quit: ";
//
//		cin >> iChar;
//
//		switch (iChar) {
//		case 1:
//			part1();
//			break;
//		case 0:
//			// the user wants to terminate
//			bProceed = false;
//			break;
//		default:
//			// the input, given by the user, is not an available option
//			cout << "The entered number is not recognized, please try again." << endl;
//		} // eof switch
//	}
//}
