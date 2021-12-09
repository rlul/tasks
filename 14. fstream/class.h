#pragma once
#pragma warning(disable: 4996)
#include <iostream>

enum gender_e {
	male, female
};

class soldier_t {
public:
	soldier_t() {};
	soldier_t(const char* name, const char* surname, const int day_of_birth, const int month_of_birth, const int year_of_birth, const gender_e gender)
		: m_day_of_birth(day_of_birth),
		  m_month_of_birth(month_of_birth),
		  m_year_of_birth(year_of_birth),
		  m_gender(gender) {
		strcpy(m_name, name);
		strcpy(m_surname, surname);
	}

	const char* get_name() const {
		return m_name;
	}
	const char* get_surname() const {
		return m_surname;
	}
	int get_day_of_birth() const {
		return m_day_of_birth;
	}
	int get_month_of_birth() const {
		return m_month_of_birth;
	}
	int get_year_of_birth() const {
		return m_year_of_birth;
	}
	const char* get_date_of_birth() const {
		char* buf = new char[16];
		sprintf(buf, "%d.%d.%d", m_day_of_birth, m_month_of_birth, m_year_of_birth);
		return buf;
	}
	gender_e get_gender() const {
		return m_gender;
	}

protected:
	char	m_name[32] { 0 };
	char	m_surname[32] { 0 };
	int		m_day_of_birth;
	int		m_month_of_birth;
	int		m_year_of_birth;
	gender_e m_gender;
};