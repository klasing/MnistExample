// Example 2.2
// boost::ptr_set with intuitively correct order
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/indirect_fun.hpp>
#include <set>
#include <memory>
#include <functional>
#include <iostream>

using namespace std;
namespace ns_example_2_2 {
	inline void example_2_2() {
		boost::ptr_set<int> s;
		s.insert(new int{ 2 });
		s.insert(new int{ 1 });
		cout << "-> " << *s.begin() << '\n';

		set<unique_ptr<int>, boost::indirect_fun<less<int>>> v;
		v.insert(unique_ptr<int>(new int{ 2 }));
		v.insert(unique_ptr<int>(new int{ 1 }));
		cout << "-> " << **v.begin() << '\n';
	}
}
// get rid of compiler comment
//int* el_1 = new int{ 2 };
//s.insert(el_1);
