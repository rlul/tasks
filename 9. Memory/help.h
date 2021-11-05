#pragma once
#include <iostream>
#include <string>

#define RAND(min, max) (rand() % (max - min)) + min

const char* names[] = { "Liam", "Olivia", "Noah", "Emma", "Oliver" "Ava", "William", "Sophia", "Elijah", "Isabella", "James", "Charlotte", "Benjamin", "Amelia", "Lucas", "Mia", "Mason", "Harper", "Ethan", "Evelyn" };
const char* surnames[] = { "Abbott", "Acevedo", "Acosta", "Burris", "Burt", "Burton", "Bush", "Castaneda", "Castillo", "Castro", "Cervantes", "Chambers", "Chan", "Chandler", "Chaney", "Duffy", "Duke", "Duncan", "Ellis", "Ellison", "Emerson", "Fowler", "Fox", "Francis", "Franco", "Gallegos", "Galloway" };

struct student_t {
	enum e_fac { null, economics, history, mathematics };

	std::string m_sName		= names[RAND(0, 19)];
	std::string m_sSurname	= surnames[RAND(0, 27)];
	e_fac m_eFaculty		= e_fac(RAND(1, 4));
	std::string m_sEmail	= m_sName + "_" + m_sSurname + "@mail.com";
};

struct student_test_t {
	enum e_fac { null, economics, history, mathematics };

	e_fac m_eFaculty		= e_fac(RAND(1, 4));
	std::string m_sSurname	= surnames[RAND(0, 27)];
	std::string m_sName		= names[RAND(0, 19)];
	std::string m_sEmail	= m_sName + "_" + m_sSurname + "@mail.com";
};

void print_info(student_t& student) {
	printf("\nStudent 0x%p:\n", &student);
	printf("- Name: %s\n", student.m_sName.c_str());
	printf("- Surname: %s\n", student.m_sSurname.c_str());
	printf("- Faculty: ");
	switch (student.m_eFaculty) {
	case student_t::economics:
		printf("Economics\n");
		break;
	case student_t::history:
		printf("History\n");
		break;
	case student_t::mathematics:
		printf("Mathematics\n");
		break;
	default:
		printf("INVALID!\n");
		break;
	}
	printf("- Email: %s\n", student.m_sEmail.c_str());
}
