#include <iostream>
#include <time.h>
#include "array.h"

#define RAND(min, max) (rand() % (max - min)) + min

void show(CArray& _arr);

int main() {
	srand(time(0));

	while (true) {

		int** arr = new int* [3];
		for (int i = 0; i < 3; i++)		// случайное заполнение массива
			arr[i] = new int[3]{ RAND(-10, 10), RAND(-10, 10), RAND(-10, 10) };

		CArray test(arr, 3, 3);

		show(test);

		printf("\ntask: %d\n", task(test));

		system("pause");
		printf("\n");
	}

	return 0;
}

void show(CArray& _arr) {
	for (int i = 0; i < _arr.get_columns(); i++) {
		for (int j = 0; j < _arr.get_rows(); j++)
			printf("%d ", _arr(i, j));
		printf("\n");
	}
}
