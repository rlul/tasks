#include <iostream>
#include "help.h"


int main() {

	// ~~~ Выделить статический массив памяти для 30 студентов. ~~~
	student_t first[30];

	// ~~~ Выделить динамический массив памяти для заранее неизвестного количество студентов ~~~
	int second_size = 0;
	printf("Size of an array: ");
	std::cin >> second_size;
	student_t* second = new student_t[second_size];

	// ~~~ Получить доступ к первому студенту из массива, используя разыменование указателя. ~~~
	print_info(*second);
	system("pause");

	// ~~~ Вычислить размер памяти, занимаемый массивом студентов. ~~~
	int arr_size = second_size * sizeof(student_t);
	printf("\nallocated size: %d\n", arr_size);
	system("pause");
	
	// ~~~ Проитерироваться по массиву студентов, используя инкремент указателя. ~~~
	for (int i = 0; i < second_size; i++)
		print_info(*(second+i));
	system("pause");

	// ~~~ Вывести в консоль адрес каждой структуры студента в памяти. Вывести сообщение о величине, на которую изменяется значение указателя при инкременте. ~~~
	printf("\ndifference: 0x%X\n", sizeof(student_t));
	system("pause");

	// ~~~ Вывести на консоль адреса соседних полей структуры. ~~~
	student_t* blank = NULL;
	printf("\nBase addresses of the fields:\n");
	printf("- Name: 0x%X\n", &blank->m_sName);
	printf("- Surname: 0x%X\n", &blank->m_sSurname);
	printf("- Faculty: 0x%X\n", &blank->m_eFaculty);
	printf("- Email: 0x%X\n", &blank->m_sEmail);
	system("pause");

	// ~~~ Создать структуру с таким же набором полей, но другой последовательностью. ~~~
	student_test_t* third = new student_test_t[second_size];
	
	// ~~~ Сравнить размеры структур. ~~~
	printf("\nstudent_t size: %d\nstudent_test_t size: %d\n", sizeof(student_t), sizeof(student_t));
	system("pause");

	// ~~~ Вывести на консоль адреса каждого поля для обеих структур. ~~~
	student_test_t* blank_test = NULL;
	printf("\nBase addresses of the fields:\n");
	printf("- Name: 0x%X\n", &blank_test->m_sName);
	printf("- Surname: 0x%X\n", &blank_test->m_sSurname);
	printf("- Faculty: 0x%X\n", &blank_test->m_eFaculty);
	printf("- Email: 0x%X\n", &blank_test->m_sEmail);
	system("pause");


	return 0;
}