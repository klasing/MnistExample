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

		bool empty() const {}
		size_t size() const {}
		T& top() {}
		T const& top() const {}
		void push(T const&) {}
		void push(T&&) {}
		void pop();
		void swap(stack&&) {}
	};
}