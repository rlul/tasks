#pragma once
#pragma warning(disable: 4996)

#include <format>
#include <vector>

#include "help.h"

#define RAND(min, max) (rand() % (max - min)) + min

class student_t {
public:
	student_t();
	student_t(const char* name, int age, int year, const char* group);
	~student_t();

	student_t(const student_t& other);
	student_t(student_t&& other) noexcept;
	student_t& operator=(const student_t& other);
	student_t& operator=(student_t&& other) noexcept;

	const char* get_name() const;
	void	set_name(const char* name);
	int		get_age() const;
	void	set_age(int age);
	int		get_year() const;
	void	set_year(int year);
	const char* get_group() const;
	void	set_group(const char* group);

private:
	char	m_name[64]{0};
	int		m_age;
	int		m_year;
	char	m_group[8]{0};
};

inline auto gen_student = [](const std::unique_ptr<student_t>& student) {
	const int year = RAND(1, 5);

	student->set_name(std::format("{} {}", names[RAND(0, 20)], surnames[RAND(0, 27)]).c_str());
	student->set_age(RAND(18, 25));
	student->set_year(year);
	student->set_group(std::format("{}-{}", groups[RAND(0, 6)], 10 - year).c_str());
};

void show(const std::vector<std::unique_ptr<student_t>>& vec);