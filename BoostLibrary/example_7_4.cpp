// Example 7.4
// Placeholders with special characters
#include <boost/format.hpp>
#include <iostream>

using namespace std;
namespace ns_example_7_4 {
	inline void example_7_4() {
		cout << boost::format{ "%|1$+| %2% %1%" } % 1 % 2 << '\n';
	}
}