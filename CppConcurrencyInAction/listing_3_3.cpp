// Listing 3.3
// The interface to the std::stack container adapter
#include <deque>

using namespace std;
namespace ns_listing_3_3 {
	template<typename T, typename Container = deque<T>>
	class stack {
	public:
		explicit stack(const Container&) {}
		explicit stack(Container&& = Container()) {}
		template<class Alloc>
		explicit stack(const Alloc&) {}
		template<class Alloc>
		explicit stack(const Container&, const Alloc&) {}
		template<class Alloc>
		explicit stack(const Container&&, const Alloc&) {}
		template<class Alloc>
		explicit stack(stack&&, const Alloc&) {}

		bool empty() const { return this->empty(); }
		size_t size() const { return this->size(); }
		T& top() { return this->front(); }
		T const& top() const { return this->front();}
		void push(T const&) {}
		void push(T&&) {}
		void pop() {}
		void swap(stack&&) {}
	};

	inline void do_something() {}

	inline void listing_3_3() {
		stack<int> s;
		// exception: stack overflow
		//if (!s.empty()) {
		//	// undefined behaviour (calling on an empty stack)
		//	int const value = s.top();
		//	s.pop();
		//	do_something();
		//}
	}
}