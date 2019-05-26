// Example 7.5
// boost::io::format_error in case of an error
#include <boost/format.hpp>
#include <iostream>

using namespace std;
namespace ns_example_7_5 {
	inline void example_7_5() {
		try {
			cout << boost::format{ "%|+| %2% %1%" } % 1 % 2 << '\n';
		}
		catch (boost::io::format_error& ex) {
			cout << ex.what() << '\n';
		}
	}
}