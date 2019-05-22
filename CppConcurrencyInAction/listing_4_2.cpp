// Listing 4.2
// std::queue interface
#include <iostream>
#include <deque>

using namespace std;
namespace ns_listing_4_2 {
	template <class T, class Container = deque<T>>
	class queue {
	public:
		explicit queue(const Container&) {}
		explicit queue(Container&& = Container()) {}

		template <class Alloc> explicit queue(const Alloc&) {}
		template <class Alloc> queue(const Container& , const Alloc&) {}
		template <class Alloc> explicit queue(Container&& , const Alloc&) {}
		template <class Alloc> explicit queue(queue&&, const Alloc&) {}

		void swap(queue& q) {}

		bool empty() const {}
		size_t size() const {}

		T& front() {}
		const T& front() const {}
		T& back() {}
		const T& back() const {}

		void push(const T& x) {}
		void push(T&& x) {}

		void pop() {}
		template <class... Args> void emplace(Args&... args) {}
	};
}