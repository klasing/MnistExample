// Example 1.9
// Using boost::intrusive_ptr
#include <boost/intrusive_ptr.hpp>
#include <atlbase.h>
#include <iostream>

using namespace std;
namespace ns_example_x_y {
	void intrusive_ptr_add_ref(IDispatch* p) { p->AddRef(); }
	void intrusive_ptr_release(IDispatch* p) { p->Release(); }

	void check_windows_folder() {

	}
	inline void example_x_y() {

	}
}