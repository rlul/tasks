#include "class.h"

#include <iostream>

#define format(x, ...) std::cout << std::##format(x, ##__VA_ARGS__)

// ~~~ CONSTRUCTOR ~~~
student_t::student_t() {
	format("[!] student_t()\n");
}

student_t::student_t(const char* name, const int age, const int year, const char* group)
	: m_age(age),
	m_year(year) {
	format("[!] student_t(const char* name, const int age, const int year, const char* group)\n");
	strcpy(m_name, name);
	strcpy(m_group, group);
}

student_t::~student_t() {
	format("[!] ~student_t()\n");
}


// ~~~ COPY / MOVE ~~~
student_t::student_t(const student_t& other)
	: m_age(other.m_age),
	m_year(other.m_year) {
	format("[!] student_t(const student_t& other)\n");
	strcpy(m_name, other.m_name);
	strcpy(m_group, other.m_group);
}

student_t::student_t(student_t&& other) noexcept
	: m_age(other.m_age),
	m_year(other.m_year) {
	format("[!] student_t(student_t&& other)\n");
	strcpy(m_name, other.m_name);
	strcpy(m_group, other.m_group);
}

student_t& student_t::operator=(const student_t& other) {
	if (this == &other)
		return *this;
	m_age = other.m_age;
	m_year = other.m_year;
	strcpy(m_name, other.m_name);
	strcpy(m_group, other.m_group);
	return *this;
}

student_t& student_t::operator=(student_t&& other) noexcept {
	if (this == &other)
		return *this;
	m_age = other.m_age;
	m_year = other.m_year;
	strcpy(m_name, other.m_name);
	strcpy(m_group, other.m_group);
	return *this;
}

// ~~~ GETTERS / SETTERS ~~~
const char* student_t::get_name() const {
	return m_name;
}

void student_t::set_name(const char* name) {
	strcpy(m_name, name);
}

int student_t::get_age() const {
	return m_age;
}

void student_t::set_age(const int age) {
	this->m_age = age;
}

int student_t::get_year() const {
	return m_year;
}

void student_t::set_year(const int year) {
	this->m_year = year;
}

const char* student_t::get_group() const {
	return m_group;
}

void student_t::set_group(const char* group) {
	strcpy(m_group, group);
}

// ~~~ ADDITIONAL FUNCTIONS ~~~
void show(const std::vector<std::unique_ptr<student_t>>& vec) {
	format(" {:^18} | {:^3} | {} | {}\n", "Name", "Age", "Year", "Group");
	format("{:=>41}\n", "");
	for (auto& elem : vec)
		format(" {:^18} | {:^3} | {:^4} | {:^5}\n", elem->get_name(), elem->get_age(), elem->get_year(), elem->get_group());
	format("\n");
}