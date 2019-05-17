// taken from:
// https://en.cppreference.com/w/cpp/thread/get_id
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
namespace ns_d_7_2_a {
	extern std::mutex g_display_mutex;
	inline void example_d_7_2_a() {
		thread::id this_id = this_thread::get_id();

		g_display_mutex.lock();
		cout << "-> thread " << this_id << " sleeping...\n";
		g_display_mutex.unlock();

		this_thread::sleep_for(chrono::seconds(1));
	}
}