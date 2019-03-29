#include "pch.h"

#include <tuple>
#include "tuple_print.hpp"
#include "tuple_print_helper.hpp"

inline int main_20_7_3_a() {
	typedef tuple<int, string, bool> MyTuple;
	MyTuple t1(16, "Test", true);
	tuple_print<tuple_size<MyTuple>::value, MyTuple> tp(t1);
	return 0;
}

template<typename T>
inline void tuple_print_(T t) {
	tuple_print_helper<tuple_size<T>::value, T> tph(t);
}

inline int main_20_7_3_b() {
	auto t1 = make_tuple(167, "Testing", false, 2.3);
	tuple_print_(t1);
	return 0;
}

inline void subParagraph_20_7_3() {
	cout << "Printing Tuples" << endl;
	cout << "---------------" << endl;

	main_20_7_3_a();
	main_20_7_3_b();
}