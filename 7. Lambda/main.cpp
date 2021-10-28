#include <iostream>
#include <vector>
#include <algorithm>


int main() {

	// ~~~ 1.1) Вывод элементов вектора лямбда-выражением ~~~
	std::vector<int> vec = { 7, 9, 1, 5, 2, 4, 3, 8, 6, 0 };
	printf(" Task 1:\n");
	std::for_each(vec.begin(), vec.end(), [](int& num) {	// - Вывод
		printf("%d ", num);
	});

	// ~~~ 1.2) Подсчёт количества перестановок элементов при сортировке ~~~
	int num_of_swaps = 0;
	std::sort(vec.begin(), vec.end(), [&num_of_swaps](int& a, int& b) {
		if (a > b)
			num_of_swaps++;
		return a > b;
	});
	printf("\n\n Task 2:\nswaps: %d\n", num_of_swaps);

	std::for_each(vec.begin(), vec.end(), [](int& num) {	// - Вывод
		printf("%d ", num);
	});

	// ~~~ 1.3) Поиск вхождения подстроки ~~~
	std::vector<std::string> words{ "ememe", "banana", "walnut", "lemon" };
	std::string substr;

	printf("\n\n Task 3:\nEnter a substring: ");
	std::cin >> substr;

	auto found = std::find_if(words.begin(), words.end(), [&substr](std::string str) {
		return str.find(substr) != std::string::npos;
	});

	if (found == words.end())
		printf("No results!\n");
	else
		printf("Found %s!\n", found->substr().c_str());
	
	// ~~~ 2.1) Генерация вектора из N-последовательных элементов ~~~
	int range_limit = 0;
	printf("\n Task 4:\nNumeric range from 0 to: ");	
	std::cin >> range_limit;
	if (range_limit < 1)
		return 1;
	std::vector<int> num_range(range_limit);
	std::for_each(num_range.begin(), num_range.end(), [](int& num) {
		static int s_num = 0;
		num = s_num++;
	});

	std::for_each(num_range.begin(), num_range.end(), [](int& num) {	// - Вывод
		printf("%d ", num);
	});

	// ~~~ 2.2) Отбросить k-элементов слева и добавить k-последовательных элементов в конец  ~~~
	std::vector<int> new_range(range_limit);
	int shift_num = 0;
	printf("\n\n Task 5:\nEnter a number of elementes to shift: ");
	std::cin >> shift_num;
	if (shift_num >= range_limit)
		return 2;
	for_each(new_range.begin(), new_range.end(), [&shift_num, &num_range](int& num) {
		static int new_num = num_range.at(shift_num);
		num = new_num++;
	});

	std::for_each(new_range.begin(), new_range.end(), [](int& num) {	// - Вывод
		printf("%d ", num);
	});
	return 0;
}
