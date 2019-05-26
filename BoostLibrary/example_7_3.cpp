// Example 7.3
// Using manipulators with boost::io::group()
#include <boost/format.hpp>
#include <iostream>

using namespace std;
namespace ns_example_7_3 {
	inline void example_7_3() {
		cout << boost::format{ "%1% %2% %1%" } % 
			boost::io::group(showpos, 1) % 2 << '\n';
	}
}