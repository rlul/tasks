#include <iostream>
#include <algorithm>

#include "myvector.h"


template<typename V> V** find_all(vector_t<V>& vec, V val);
template<class V, class P> V* find_if(vector_t<V>& vec, P pred);

int main() {

	vector_t<int> test = { 0, 0, 1, 0, 1, 1, 0 };
	int** found = find_all<int>(test, 1);
	for (int i = 0; i < 3; i++)
		printf("%p (%d), ", found[i], *found[i]);

	int* found1 = find_if(test, [](int a) -> bool {return a; });
	printf("\n%p (%d)\n", found1, *found1);

	return 0;
}

template<typename V>
V** find_all(vector_t<V>& vec, V val) {
	V** data = new V * [vec.size()];
	int iter = 0;
	for (const auto& elem : vec)
		if (elem == val)
			data[iter++] = (V*)&elem;

	return data;
}

template<class V, class P>
V* find_if(vector_t<V>& vec, P pred) {
	for (const auto& elem : vec)
		if (pred(elem))
			return (V*)&elem;
	return vec.end();
}