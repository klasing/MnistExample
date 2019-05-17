#include <iostream>
#include <iomanip>
#include <ctime>

#include "example_d_7_2_a.cpp"
#include "example_d_7_2_b.cpp"

using namespace std;
inline void paragraph_d_7_2() {
	cout << "D.7.2 Namespace this_thread" << endl;
	cout << "---------------------------" << endl;

	cout << "a) get_id()" << endl;
	using namespace ns_d_7_2_a;
	thread t1(example_d_7_2_a);
	thread t2(example_d_7_2_a);
	t1.join();
	t2.join();

	cout << "b) yield()" << endl;
	using namespace ns_d_7_2_b;
	auto start = chrono::high_resolution_clock::now();
	example_d_7_2_b(chrono::microseconds(100));
	auto elapsed = chrono::high_resolution_clock::now() - start;
	cout << "-> waited for "
		<< chrono::duration_cast<chrono::microseconds>(elapsed).count()
		<< " microseconds\n";

	cout << "c) sleep_for()" << endl;
	using namespace chrono_literals;
	cout << "-> Hello waiter\n" << flush;
	auto start_ = chrono::high_resolution_clock::now();
	this_thread::sleep_for(2s);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> elapsed_ = end - start_;
	cout << "Waited " << elapsed_.count() << " ms\n";
	// taken from:
	// http://www.cplusplus.com/reference/thread/this_thread/sleep_for/
	cout << "-> countdown:\n";
	for (int i = 10; i > 0; --i) {
		cout << "-> " << i << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout << "-> liftoff" << endl;

	cout << "d) sleep_until()" << endl;
	// taken from:
	// http://www.cplusplus.com/reference/thread/this_thread/sleep_until/
	// this results in a compiler error C4996
	// Consider using localtime_s instead
	
	//using chrono::system_clock;
	//time_t tt = system_clock::to_time_t(system_clock::now());
	////#pragma warning(suppress : 4996)
	//struct tm* ptm = localtime(&tt);
	//cout << "-> Current time: " << put_time(ptm, "%x") << '\n';
	//cout << "-> Waiting for the next minute to begin...\n";
	//++ptm->tm_min;
	//ptm->tm_sec = 0;
	//this_thread::sleep_until(system_clock::from_time_t(mktime(ptm)));
	//cout << put_time(ptm, "-> %x") << " reached!\n";

	//using chrono::system_clock;
	//time_t tt = system_clock::to_time_t(system_clock::now());
	//struct tm newtime;
	//localtime_s(&newtime, &tt);
	//cout << "-> Current time: " << put_time(&newtime, "%x") << '\n';
	//cout << "-> Waiting for the next minute to begin...\n";
	//++newtime.tm_min;
	//newtime.tm_sec = 0;
	//this_thread::sleep_until(system_clock::from_time_t(mktime(&newtime)));
	//cout << put_time(&newtime, "-> %x") << " reached!\n";

	// both examples results in outputting a date format, 
	// instead of a time format, so a conversion from the newtime variable
	// into a char buffer (timebuf variable) has to take place
	//char timebuf[32];
	// Convert to an ASCII representation
	// look at:
	// https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s?view=vs-2019
	//asctime_s(timebuf, 32, &newtime);
	//printf("-> %.19s reached\n", timebuf);

	char timebuf[32];
	using chrono::system_clock;
	time_t tt = system_clock::to_time_t(system_clock::now());
	struct tm newtime;
	localtime_s(&newtime, &tt);
	asctime_s(timebuf, 32, &newtime);
	printf("-> Current time: %.19s\n", timebuf);
	cout << "-> Waiting for the next minute to begin...\n";
	++newtime.tm_min;
	newtime.tm_sec = 0;
	this_thread::sleep_until(system_clock::from_time_t(mktime(&newtime)));
	asctime_s(timebuf, 32, &newtime);
	printf("-> %.19s reached\n", timebuf);
}
