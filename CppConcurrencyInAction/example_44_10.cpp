// taken from:
// https://theboostcpplibraries.com/boost.thread-synchronization
// Example 44.10 Shared locks with boost::shared_lock
// Problem with linker is solved. Look at:
// https://stackoverflow.com/questions/13042561/fatal-error-lnk1104-cannot-open-file-libboost-system-vc110-mt-gd-1-51-lib
// Perform the steps described by:
// You need to tell the linker where to look for libraries to link to.
// To access this setting, right - click on the project name in the Solution Explorer window,
// then Properties -> Linker -> General -> Additional Library Directories.
// Enter <boost_path>\stage\lib here (this is the path where the libraries are
// located if you build Boost using default options).
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
namespace ns_example_44_10 {
	inline void wait(int seconds) {
		boost::this_thread::sleep_for(boost::chrono::seconds{ seconds });
	}

	extern boost::shared_mutex mutex;
	extern vector<int> random_numbers;

	inline void fill() {
		srand(static_cast<unsigned int>(time(0)));
		for (int i = 0; i < 3; ++i) {
			boost::unique_lock<boost::shared_mutex> lock{ mutex };
			random_numbers.push_back(rand());
			lock.unlock();
			wait(1);
		}
	}

	inline void print() {
		for (int i = 0; i < 3; ++i) {
			wait(1);
			boost::shared_lock<boost::shared_mutex> lock{ mutex };
			cout << "-> " << random_numbers.back() << '\n';
		}
	}

	extern int sum;

	inline void count() {
		for (int i = 0; i < 3; ++i) {
			wait(1);
			boost::shared_lock<boost::shared_mutex> lock{ mutex };
			sum += random_numbers.back();

		}
	}

	inline void example_44_10() {
		boost::thread t1{ fill }, t2{ print }, t3{ count };
		t1.join();
		t2.join();
		t3.join();
		cout << "-> Sum: " << sum << '\n';
	}
}

