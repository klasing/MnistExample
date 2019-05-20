// Listing 2.6
// scoped_thread and example usage
#include <iostream>
#include <thread>
#include <stdexcept>

using namespace std;
namespace ns_listing_2_6 {
	class scoped_thread {
		thread t;
	public:
		explicit scoped_thread(thread t_) :
		t(move(t_)) {
			cout << "-> [listing 2.6] <<constructor>> scoped_thread()" << endl;
			if (!t.joinable())
				throw logic_error("No thread");
		}
		~scoped_thread() { 
			cout << "-> [listing 2.6] <<destructor>> scoped_thread()" << endl;
			t.join();
		}
		scoped_thread(scoped_thread const&) = delete;
		scoped_thread& operator- (scoped_thread const&) = delete;
	};

	struct func;

	inline void do_something_in_current_thread() {
		cout << "-> [listing 2.6] doing something in current thread" << endl;
	}

	inline void f() {
		//int some_local_state;
		//// constructor is never called???
		//scoped_thread t(thread(func(some_local_state)));

		//do_something_in_current_thread();
	}
}