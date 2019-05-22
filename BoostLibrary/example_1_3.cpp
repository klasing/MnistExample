// Example 1.3
// Using boost::shared_ptr
#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace std;
namespace ns_example_1_3 {
	inline void example_1_3() {
		boost::shared_ptr<int> p1{ new int{1} };
		cout << "-> " << *p1 << '\n';
		boost::shared_ptr<int> p2{ p1 };
		p1.reset(new int{ 2 });
		cout << "-> " << *p1.get() << '\n';
		p1.reset();
		cout << "-> " << boolalpha << static_cast<bool>(p2) << '\n';
	}
}