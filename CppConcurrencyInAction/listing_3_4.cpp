// Listing 3.4
// An outline class definition for a thread-safe stack
#include <exception>
#include <memory>

using namespace std;
namespace ns_listing_3_4 {
	struct empty_stack : exception {
		const char* what() const throw() {}
	};

	template<typename T>
	class threadsafe_stack {
	public:
		threadsafe_stack() {}
		threadsafe_stack(const threadsafe_stack&) {}
		threadsafe_stack& operator=(const threadsafe_stack&) = delete {}

		void push(T new_value) {}
		shared_ptr<T> pop() {}
		void pop(T& value) {}
		bool empty() const {}
	};
}

