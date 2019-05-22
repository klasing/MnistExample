// Example 1.8
// Using boost::weak_ptr
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <thread>
#include <functional>
#include <iostream>

using namespace std;
namespace ns_example_1_8 {
	inline void reset(boost::shared_ptr<int>& sh) {
		sh.reset();
	}
	inline void print(boost::weak_ptr<int>& w) {
		boost::shared_ptr<int> sh = w.lock();
		if (sh)
			// it's not entirely certain that the output gets printed
			cout << "-> " << *sh << '\n';
	}
	inline void example_1_8() {
		boost::shared_ptr<int> sh{ new int{99} };
		boost::weak_ptr<int> w{ sh };
		thread t1{ reset, ref(sh) };
		thread t2{ print, ref(w) };
		t1.join();
		t2.join();
	}
}