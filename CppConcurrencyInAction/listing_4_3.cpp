// Listing 4.3
// The interface of your threadsafe_queue
#include <memory> // for std::shared_ptr

using namespace std;
namespace ns_listing_4_3 {
	template <typename T>
	class threadsafe_queue {
	public:
		threadsafe_queue() {}
		threadsafe_queue(const threadsafe_queue&) {}
		// disallow assignment for simplicity
		threadsafe_queue& operator=(const threadsafe_queue) = delete;

		void push(T new_value) {}

		bool try_pop(T& vlaue) {} // (1)
		shared_ptr<T> wait_and_pop() {} // (2)

		bool empty() const {}
	};

}