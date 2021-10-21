#include <iostream>

#define SUM(a) a.grades[0] + a.grades[1] + a.grades[2]

struct student_t {
	char surname[64];
	char name[64];
	int	 grades[3];
};

void show(student_t* _arr, int _size);
void sort(student_t* _arr, int _size);

int main() {
	int size = 0;
	do {
		printf("Enter a number of students ( >= 5 ) : ");
		std::cin >> size;
		if (size < 5)
			printf("Invalid option!\n");
	} while (size < 5);
	student_t* pStudents = new student_t[size];
	for (int i = 0; i < size; i++) {
		printf("- Student #%d\n", i);
		printf("Surname : ");
		std::cin >> pStudents[i].surname;
		printf("Name : ");
		std::cin >> pStudents[i].name;
		printf("Grades : ");
		std::cin >> pStudents[i].grades[0];
		std::cin >> pStudents[i].grades[1];
		std::cin >> pStudents[i].grades[2];
	}

	show(pStudents, size);

	sort(pStudents, size);
	show(pStudents, size);

	delete[] pStudents;

	return 0;
}

void show(student_t* _arr, int _size) {
	for (int i = 0; i < _size; i++) {
		printf("- Student #%d\n", i);
		printf("Surname : %s\n", _arr[i].surname);
		printf("Name : %s\n", _arr[i].name);
		printf("Grades : %d, %d, %d, %d\n", _arr[i].grades[0], _arr[i].grades[1], _arr[i].grades[2], SUM(_arr[i]));
	}
}

void sort(student_t* _arr, int _size) {	// decr, sum of 3
	printf("\n####### Sorting... #######\n");
	bool flag;
	for (int i = 0; i < _size; i++) {
		flag = true;
		for (int j = 0; j < _size - (i + 1); j++) {
			if (SUM(_arr[j]) < SUM(_arr[j + 1])) {
				flag = false;
				std::swap(_arr[j], _arr[j + 1]);
			}
		}
		if (flag)
			return;
	}
}