#include <iostream>

#include "myvector.h"

#define RAND(min, max) (rand() % (max - min)) + min

template<typename T> void show(vector_t<T>&);
template<typename T> void show_info(vector_t<T>&);

int main() {

	vector_t<int> vec = { 1, 2, 3 };
	show(vec);
	show_info(vec);

	vec.at(5) = 4;
	show(vec);
	show_info(vec);

	vec.push(999);
	show(vec);
	show_info(vec);

	printf("pop: %d\n", vec.pop());
	show(vec);
	show_info(vec);

	return 0;
}

template<typename T>
void show(vector_t<T>& vec) {
	for (const auto& obj : vec)
		printf("%d ", obj);
	printf("\n");
}
template<typename T>
void show_info(vector_t<T>& vec) {
	printf("cap: %d, size: %d\n", vec.capacity(), vec.size());
	printf("first: %p, last: %p\n", vec.begin(), vec.end());

}