#include "myvector.h"

// ~~~ SORT ~~~
void merge(vector_t<int>& vec, int* L, int* R, int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	for (i = 0; i < n1; i++) {
		L[i] = vec[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = vec[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] < R[j]) {
			vec[k] = L[i];
			i++;
		}
		else {
			vec[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		vec[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		vec[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(vector_t<int>& vec, int l, int r, int* L, int* R) {
	if (l < r) {
		int m = l + (r - l) / 2;
		merge_sort(vec, l, m, L, R);
		merge_sort(vec, m + 1, r, L, R);
		merge(vec, L, R, l, m, r);
	}
}

void MergeSort(vector_t<int>& vec) {
	int* L = new int[vec.size()/2];
	int* R = new int[vec.size()/2];
	merge_sort(vec, 0, vec.size() - 1, L, R);
};

void CountSort(vector_t<int>& vec) {
	int max, min, L, k;
	max = INT_MIN;
	min = INT_MAX;
	for (const auto& num : vec) {
		if (num > max)
			max = num;
		if (num < min)
			min = num;
	}
	L = max - min + 1;
	int* B = new int[L] {0};
	for (const auto& num : vec)
		B[num - min]++;
	k = 0;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < B[i]; j++)
			vec[k++] = i + min;
}