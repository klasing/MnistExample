// Listing A.1
// A class with a move constructor
#include <algorithm>

using namespace std;
namespace ns_listing_A_1 {
	class X {
	private:
		int* data;
	public:
		X() : data(new int[1000000]) {}
		~X() { delete[] data; }
		// copy constructor
		X(const X& other) : data(new int[1000000]) {
			copy(other.data, other.data + 1000000, data);
		}
		// move constructor
		X(X&& other) : data(other.data) {
			other.data = nullptr;
		}
	};
}