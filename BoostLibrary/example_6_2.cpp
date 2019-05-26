// Example 6.2
// boost::lexical_cast in case of an error
#include <boost/lexical_cast.hpp>
#include <string>
#include <iostream>

using namespace std;
namespace ns_example_6_2 {
	inline void example_6_2() {
		try {
			int i = boost::lexical_cast<int>("abc");
			cout << "-> " << i << '\n';
		}
		catch (const boost::bad_lexical_cast& e) {
			cerr << "-> " << e.what() << '\n';
		}
	}
}