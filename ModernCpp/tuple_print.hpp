#pragma once

#include <string> // this avoids the need for c_str()!
#include <typeinfo>

template<int n, typename TupleType>
class tuple_print {
public:
	tuple_print(TupleType t) {
		tuple_print<n - 1, TupleType> tp(t);
		cout << "-> " << get<n - 1>(t) << endl;
	}
};

template<typename TupleType>
class tuple_print<0, TupleType> {
public:
	tuple_print(TupleType t) {}
};

