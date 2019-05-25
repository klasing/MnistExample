// Example 3.2
// Boost.ScopeExit with C++11 lambda functions
#include <iostream>
#include <utility>

using namespace std;
namespace ns_example_3_2 {
	template <typename T>
	struct scope_exit {
		scope_exit(T&& t) : t_{move(t)} {}
		~scope_exit() { t_(); }
		T t_;
	};

	template <typename T>
	inline scope_exit<T> make_scope_exit(T&& t) {
		return scope_exit<T>{ move(t) };
	}

	inline int* foo() {
		int* i = new int{ 10 };
		auto cleanup = make_scope_exit([&i]() { delete i; i = 0; });
		cout << "-> " << *i << '\n';
		return i;
	}

	inline void example_3_2() {
		int* j = foo();
		cout << "-> " << j << '\n';
	}
}