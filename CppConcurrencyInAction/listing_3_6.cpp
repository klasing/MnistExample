// Listing 3.6
// Using std::lock() and std::lock_guard in a swap operation
#include <mutex>

using namespace std;
namespace ns_listing_3_6 {
	class some_big_object {};
	inline void my_swap(some_big_object& lhs, some_big_object& rhs) {}

	class X {
	private:
		some_big_object some_detail;
		mutex m;
	public:
		X(some_big_object const& sd) : some_detail(sd) {}
		friend void my_swap(X& lhs, X& rhs) {
			if (&lhs == &rhs)
				return;
			lock(lhs.m, rhs.m);
			lock_guard<mutex> lock_a(lhs.m, adopt_lock);
			lock_guard<mutex> lock_b(rhs.m, adopt_lock);
			my_swap(lhs.some_detail, rhs.some_detail);
		}
	};
}