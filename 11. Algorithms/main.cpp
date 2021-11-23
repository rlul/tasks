#include <iostream>
#include <vector>
#include <algorithm>

#include "myvector.h"
#include "timer.h"

#define RAND(min, max) (rand() % (max - min)) + min

template<typename T> void show(vector_t<T>&);
template<typename T> void show_info(vector_t<T>&);

template<typename C, typename V>
V** find_all(C& c, V v) {
	V** data = new V*[c.size()];
	int iter = 0;
	for (const auto& elem : c)
		if (elem == v)
			data[iter++] = (V*)&elem;
			
	return data;
}

int main() {

	constexpr int iterations = 1;
	constexpr int count = 1000;

	std::vector<int> base(count), stdvec;
	vector_t<int> myvec;
	Timer timer;
	int total_time;

	for (auto& elem : base) {
		elem = RAND(0, 1000);
		stdvec.push_back(elem);
		myvec.push(elem);
	}

	// ~~~ COUNT SORT ~~~
	total_time = 0;		// reset total time
	for (int i = 0; i < iterations; i++) {
		timer.start();
		CountSort(myvec);
		timer.stop();
		total_time += timer.microseconds();
		for (int i = 0; i < count; i++)
			myvec[i] = base[i];
	}
	printf("count sort : %d\n", total_time / iterations);

	// ~~~ MERGE SORT ~~~
	total_time = 0;		// reset total time
	for (int i = 0; i < iterations; i++) {
		timer.start();
		MergeSort(myvec);
		timer.stop();
		total_time += timer.microseconds();
		for (int i = 0; i < count; i++)
			myvec[i] = base[i];
	}
	printf("merge sort : %d\n", total_time / iterations);

	// ~~~ STD::SORT ~~~
	total_time = 0;		// reset total time
	for (int i = 0; i < iterations; i++) {
		timer.start();
		std::sort(stdvec.begin(), stdvec.end());
		timer.stop();
		total_time += timer.microseconds();
		for (int i = 0; i < count; i++)
			stdvec[i] = base[i];
	}
	printf("std::sort : %d\n", total_time / iterations);

	// ~~~ LINEAR SEARCH ~~~
	total_time = 0;		// reset total time
	for (int i = 0; i < iterations; i++) {
		timer.start();
		LinearSearch(myvec, RAND(0, 1000));
		timer.stop();
		total_time += timer.microseconds();
	}
	printf("linear search : %f\n", static_cast<double>(total_time) / iterations);

	// ~~~ std::find ~~~
	total_time = 0;		// reset total time
	for (int i = 0; i < iterations; i++) {
		timer.start();
		std::find(stdvec.begin(), stdvec.end(), RAND(0, 1000));
		timer.stop();
		total_time += timer.microseconds();
	}
	printf("std::find : %f\n", static_cast<double>(total_time) / iterations);

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