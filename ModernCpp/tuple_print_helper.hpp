#pragma once

template<int n, typename TupleType>
class tuple_print_helper {
public:
	tuple_print_helper(TupleType t) {
		tuple_print_helper<n - 1, TupleType> tp(t);
		cout << "-> " << get<n - 1>(t) << endl;
	}
};

template<typename TupleType>
class tuple_print_helper<0, typename TupleType> {
public:
	tuple_print_helper(TupleType t) {}
};

