// Example 1.7
// boost::shared_ptr with BOOST_SP_USE_QUICK_ALLOCATOR
#define BOOST_SP_USE_QUICK_ALLOCATOR
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <ctime>

using namespace std;
namespace ns_example_1_7 {
	inline void example_1_7() {
		boost::shared_ptr<int> p;
		time_t then = time(nullptr);
		for (int i = 0; i < 1000000; ++i)
			p.reset(new int{ i });
		time_t now = time(nullptr);
		cout << "-> " << now - then << '\n';
	}
}