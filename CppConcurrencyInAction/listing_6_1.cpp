// Listing 6.1
// A class definition for a thread-safe stack
#include <exception>
#include <stack>
#include <mutex>

using namespace std;
namespace ns_listing_6_1 {
	struct empty_stack : exception {
		const char* what() const throw();
	};

	template<typename T>
	class threadsafe_stack {
	private:
		stack<T> data;
		mutable mutex m;
	public:
		threadsafe_stack() {}
		threadsafe_stack(const threadsafe_stack& other) {
			lock_guard<mutex> lock(other.m);
			data = other.data;
		}
		threadsafe_stack& operator=(const threadsafe_stack&) = delete;

		void push(T new_value) {
			lock_guard<mutex> lock(m);
			data.push(move(new_value)); // (1)
		}
		shared_ptr<T> pop() {
			lock_guard<mutex> lock(m);
			if (data.empty()) throw empty_stack(); // (2)
			shared_ptr<T> const res(
				make_shared<T>(move(data.top()))); // (3)
			data.pop(); // (4)
			return res;
		}
		void pop(T& value) {
			lock_guard<mutex> lock(m);
			if (data.empty()) throw empty_stack();
			value = move(data.top()); // (5)
			data.pop(); // (6)
		}
		bool empty() const {
			lock_guard<mutex> lock(m);
			return data.empty();
		}
	};

	inline void listing_6_1() {

	}
}