// Listing A.2
// A simple move-only type
#include <memory>
#include <algorithm>

using namespace std;
namespace ns_listing_A_2 {
	class my_class {};
	class move_only {
		unique_ptr<my_class> data;
	public:
		move_only() {}
		move_only(const move_only&) = delete;
		move_only(move_only&& other) : data(move(other.data)) {}
		move_only& operator=(const move_only&) = delete;
		move_only& operator=(move_only&& other) {
			data = move(other.data);
			return *this;
		}
	};
}