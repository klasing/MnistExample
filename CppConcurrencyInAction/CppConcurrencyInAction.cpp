#include <iostream>

#include "part3.cpp"
#include "part4.cpp"
#include "part5.cpp"
#include "part6.cpp"
#include "partD.cpp"

// used in listing_3_1.cpp
list<int> ns_listing_3_1::some_list;
mutex ns_listing_3_1::some_mutex;
// used in listing_3_2.cpp
ns_listing_3_2::some_data* ns_listing_3_2::unprotected;
ns_listing_3_2::data_wrapper ns_listing_3_2::x;
// used in listing_3_11.cpp
struct ns_listing_3_11::some_resource;
std::shared_ptr<ns_listing_3_11::some_resource> ns_listing_3_11::resource_ptr;
std::mutex ns_listing_3_11::resource_mutex;
// used in listing_4_1.cpp
std::mutex ns_listing_4_1::mut;
std::queue<ns_listing_4_1::data_chunk> ns_listing_4_1::data_queue;
std::condition_variable ns_listing_4_1::data_cond;
int ns_listing_4_1::nPrepare = 0;
int ns_listing_4_1::nProcess = 0;
const int ns_listing_4_1::NCHUNK = 10;

// used in example_5_1.cpp
atomic_flag ns_example_5_1::lock_stream = ATOMIC_FLAG_INIT;
stringstream ns_example_5_1::stream;

// used in listing_5_1.cpp
class ns_listing_5_1::spinlock_mutex;
ns_listing_5_1::spinlock_mutex ns_listing_5_1::sm;
stringstream ns_listing_5_1::stream;

// used in listing_5_2.cpp
vector<int> ns_listing_5_2::data;
atomic<bool> ns_listing_5_2::data_ready(false);

// used in listing_5_4.cpp
atomic<bool> ns_listing_5_4::x, ns_listing_5_4::y;
atomic<int> ns_listing_5_4::z;

// used in listing_5_5.cpp
atomic<bool> ns_listing_5_5::x, ns_listing_5_5::y;
atomic<int> ns_listing_5_5::z;

// used in listing_5_6.cpp
atomic<int> ns_listing_5_6::x(0), ns_listing_5_6::y(0), ns_listing_5_6::z(0);
atomic<bool> ns_listing_5_6::go;
class ns_listing_5_6::read_values;
constexpr int loop_count = 10;
ns_listing_5_6::read_values ns_listing_5_6::values1[loop_count];
ns_listing_5_6::read_values ns_listing_5_6::values2[loop_count];
ns_listing_5_6::read_values ns_listing_5_6::values3[loop_count];
ns_listing_5_6::read_values ns_listing_5_6::values4[loop_count];
ns_listing_5_6::read_values ns_listing_5_6::values5[loop_count];

// used in listing_5_7.cpp
atomic<bool> ns_listing_5_7::x, ns_listing_5_7::y;
atomic<int> ns_listing_5_7::z;

// used in listing_5_8.cpp
atomic<bool> ns_listing_5_8::x, ns_listing_5_8::y;
atomic<int> ns_listing_5_8::z;

// used in listing_5_9.cpp
atomic<int> ns_listing_5_9::data[5];
atomic<bool> ns_listing_5_9::sync1(false), ns_listing_5_9::sync2(false);

// used in listing_5_10.cpp
class ns_listing_5_10::X;
atomic<ns_listing_5_10::X*> ns_listing_5_10::p;
atomic<int> ns_listing_5_10::a;

// used in listing_5_11.cpp
vector<int> ns_listing_5_11::queue_data;
atomic<int> ns_listing_5_11::count;

// used in listing_5_12.cpp
atomic<bool> ns_listing_5_12::x, ns_listing_5_12::y;
atomic<int> ns_listing_5_12::z;

// used in listing_5_13.cpp
bool ns_listing_5_13::x;
atomic<bool> ns_listing_5_13::y;
atomic<int> ns_listing_5_13::z;


// used in example_44_10.cpp (belongs to paragraph_3_3_3.cpp)
boost::shared_mutex ns_example_44_10::mutex;
vector<int> ns_example_44_10::random_numbers;
int ns_example_44_10::sum = 0;

// used in example_d_7_2_a.cpp
std::mutex ns_d_7_2_a::g_display_mutex;

// used in cppref_use_atomic_flag.cpp
//atomic_flag ns_cppref_use_atomic_flag::lock_stream = ATOMIC_FLAG_INIT;
//stringstream ns_cppref_use_atomic_flag::stream;

int main() {
	bool bProceed = true;
	unsigned iChar = 0;

	while (bProceed) {
		cout << "C++ Concurency In Action" << endl;
		cout << "========================" << endl;
		//cout << " 1) Hello, world of concurrency in C++!" << endl;
		cout << " 3) Sharing data between threads" << endl;
		cout << " 4) Synchronizing concurrent operations" << endl;
		cout << " 5) The C++ memory model and operations on atomic types" << endl;
		cout << " 6) Designing lock-based concurrent data structures" << endl;
		cout << "12) C++ Thread Library reference" << endl;
		cout << "Enter the number of a subject, or enter a zero to quit: ";

		cin >> iChar;

		switch (iChar) {
		case 3:
			part3();
			break;
		case 4:
			part4();
			break;
		case 5:
			part5();
			break;
		case 6:
			part6();
			break;
		case 12:
			partD();
			break;
		case 0:
			// the user wants to terminate
			bProceed = false;
			break;
		default:
			// the input, given by the user, is not an available option
			cout << "The entered number is not recognized, please try again." << endl;
		} // eof switch
	}
}
//#include <iostream>
//#include <thread>
//#include <utility>
//
////#include "part1.cpp"
//#include "listing_1_1.cpp"
//#include "listing_2_1.cpp"
//#include "listing_2_2.cpp"
//#include "listing_2_3.cpp"
//#include "listing_2_4.cpp"
//#include "listing_2_5.cpp"
//#include "listing_2_6.cpp"
//#include "listing_2_7.cpp"
//#include "listing_2_8.cpp"
//#include "listing_3_1.cpp"
//
//#include "listing_A_1.cpp"
//#include "listing_A_2.cpp"
//#include "listing_A_3.cpp"
//#include "listing_A_4.cpp"
//
//using namespace std;
//// used in listing_3_1.cpp
//namespace ns_listing_3_1 {
//	list<int> some_list;
//	mutex some_mutex;
//}
//namespace ns_listing_A_4 {
//	condition_variable cond;
//	bool data_ready;
//	mutex m;
//}
//
//int main() {
//	using namespace ns_listing_1_1;
//	thread t(hello);
//	t.join();
//	using namespace ns_listing_2_1;
//	oops();
//	using namespace ns_listing_2_2;
//	try {
//		f();
//	}
//	catch (...) {
//		cout << "-> [main] exception catched" << endl;
//	}
//	using namespace ns_listing_2_3;
//	try {
//		ns_listing_2_3::f();
//	}
//	catch (...) {
//		cout << "-> [main] exception catched" << endl;
//	}
//	using namespace ns_listing_2_4;
//	// the functional behaviour in this example, is not like it should be
//	edit_document("first file name");
//	using namespace ns_listing_2_5;
//	thread t1(ns_listing_2_5::f());
//	thread t2(ns_listing_2_5::g());
//	t1.join();
//	t2.join();
//	using namespace ns_listing_2_6;
//	ns_listing_2_6::f();
//	using namespace ns_listing_2_7;
//	ns_listing_2_7::f();
//	using namespace ns_listing_2_8;
//	ns_listing_2_8::f();
//	using namespace ns_listing_3_1;
//	// TODO
//	using namespace ns_listing_A_1;
//	X x1;
//	X x2 = move(x1);
//	X x3 = static_cast<X&&>(x2);
//	using namespace ns_listing_A_2;
//	move_only m1;
//	// Error, copy constructor is declared deleted
//	// compiler complains: attemting to reference a deleted function
//	//move_only m2(m1);
//	// OK, move constructor found
//	move_only m3(move(m1));
//	using namespace ns_listing_A_3;
//	CX cx1(1, 2);
//	CX cx2 = create_cx();
//	CX cx3 = clone(cx1);
//	int array[foo_squared(half_double(make_cx(10)))];
//	using namespace ns_listing_A_4;
//	thread t_a4(wait_for_data);
//	ns_listing_A_4::data_ready = true;
//	t_a4.join();
//}
