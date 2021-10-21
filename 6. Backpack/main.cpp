#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define RAND(min, max) (rand() % (max - min)) + min

#define WEIGHT_LIMIT 5000
#define ITEM_RANGE_SIZE 15

struct item_t {
	int m_cost		= RAND(1, 50);
	int m_weight	= RAND(100, 1500);
};

int main() {

	srand(time(0));
	std::vector<item_t> backpack;
	std::vector<item_t> item_range(ITEM_RANGE_SIZE);

	// ~~~ Вывод предметов ~~~
	printf("Item range:\n");
	for (const auto item : item_range)
		printf("- cost: $%d, weight %dg\n", item.m_cost, item.m_weight);

	// ~~~ Сортировка по соотношению цена/вес ~~~
	std::sort(item_range.begin(), item_range.end(),		
		[](const item_t& a, const item_t& b) {
			return (static_cast<float>(a.m_cost) / a.m_weight) > (static_cast<float>(b.m_cost) / b.m_weight);
	});

	// ~~~ Вывод предметов после сортировки ~~~
	printf("\nItem range ( after sorting ):\n");
	for (const auto item : item_range)
		printf("- cost: $%d, weight %dg\n", item.m_cost, item.m_weight);

	// ~~~ Нахождение количества предметов, умещаемых в рюкзаке по весу ~~~
	int num_of_items = 0;
	for (int sum = 0; num_of_items < ITEM_RANGE_SIZE; num_of_items++) {
		sum += item_range.at(num_of_items).m_weight;
		if (sum > WEIGHT_LIMIT) break;
	}

	// ~~~ Заполнение рюкзака предметами ~~~
	backpack.assign(item_range.begin(), item_range.begin() + num_of_items);

	// ~~~ Вывод предметов в рюкзаке ~~~
	printf("\nBackpack:\n");
	for (const auto item : backpack)
		printf("- cost: $%d, weight %dg\n", item.m_cost, item.m_weight);

	return 0;
}