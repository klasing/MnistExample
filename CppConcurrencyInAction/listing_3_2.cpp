// Listing 3.2
// Accidentally passing out a reference to protected data
#include <string>
#include <mutex>

using namespace std;
namespace ns_listing_3_2 {
	class some_data {
		int a;
		string b;
	public:
		void do_something() {}
	};
	class data_wrapper {
		some_data data;
		mutex m;
	public:
		template<typename Function>
		void process_data(Function func) {
			lock_guard<mutex> l(m);
			func(data);
		}
	};
	extern some_data* unprotected;
	inline void malicious_funtion(some_data& protected_data) {
		unprotected = &protected_data;
	}
	extern data_wrapper x;
	inline void foo() {
		x.process_data(malicious_funtion);
		unprotected->do_something();
	}
}