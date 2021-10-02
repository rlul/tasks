#include <iostream>
#include <time.h>
#include "vector.h"

int main() {
	srand(time(0));								// setting random seed


	// fisrt
	int arr[10];

	for (int i = 0; i < 10; i++)				// random fill
		arr[i] = (rand() % 20) - 10;

	CVector first(arr, 5);
	printf("  First vector :\n");				// console log
	for (int i = 0; i < first.length(); i++)
		printf(" %d ", first[i]);
	printf("\n");

	first.sort();
	printf("  First vector ( after sort ) :\n");	// console log (after sorting)
	for (int i = 0; i < first.length(); i++)
		printf(" %d ", first[i]);
	printf("\n\n");

	// second
	CVector second;

	for (int i = 0; i < 10; i++)				// random fill
		second.push((rand() % 20) - 10);

	printf("  Second vector :\n");
	for (int i = 0; i < second.length(); i++)	// console log
		printf(" %d ", second[i]);
	printf("\n");

	second.task();
	printf("  Second vector ( after task ) :\n");	// console log (after doing the task)
	for (int i = 0; i < second.length(); i++)
		printf(" %d ", second[i]);
	printf("\n");
	return 0;
}