// Example 1.1
// Using boost::scoped_ptr
#include <boost/scoped_ptr.hpp>
#include <iostream>

using namespace std;
namespace ns_example_1_1 {
	inline void example_1_1() {
		boost::scoped_ptr<int> p{ new int{1} };
		cout << "-> " << *p << '\n';
		p.reset(new int{ 2 });
		cout << "-> " << *p.get() << '\n';
		p.reset();
		cout << "-> " << boolalpha << static_cast<bool>(p) << '\n';
	}
}