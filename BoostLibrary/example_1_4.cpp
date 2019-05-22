// Example 1.4
// boost::shared_ptr with a user-defined deleter
#include <boost/shared_ptr.hpp>
#include <Windows.h>

using namespace std;
namespace ns_example_1_4 {
	inline void example_1_4() {
		boost::shared_ptr<void> handle(OpenProcess(PROCESS_SET_INFORMATION, FALSE,
			GetCurrentProcessId()), CloseHandle);
	}
}