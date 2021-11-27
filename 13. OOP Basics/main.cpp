#include <iostream>

#include "myvector.h"


void test(vector_t<int> t) {
	return;
}

int main() {

	auto vec = vector_t{ 1, 2, 3, 4, 5, 6 };

	printf("vec: ");
	for (const auto& elem : vec)
		printf("%d ", elem);
	printf("\n\n");

#define TEST
#ifdef TEST

	printf("test is being called!\n");
	test(std::move(vec));
	printf("test has been called.\n\n");

#else

	printf("vectorview_t is being created!\n");
	vectorview_t testview(vec);
	printf("vectorview_t has been created!\n\n");

#endif // TEST

	return 0;
}
