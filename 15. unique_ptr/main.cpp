#include "class.h"
#include "comp.h"

#include <vector>
#include <algorithm>

int main() {
	std::vector<std::unique_ptr<student_t>> students(10);
	for (auto& elem : students)
		elem = std::make_unique<student_t>();
	std::ranges::for_each(students, gen_student);

	show(students);

	std::ranges::sort(students, student_comp(student_comp::group));

	show(students);

	students.erase(students.begin(), students.end());

	return 0;
}