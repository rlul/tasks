#pragma once
#include "class.h"

class student_comp {
public:
	enum method { name, age, year, group };

	student_comp(method method)
		: m_method(method)
	{}

	bool operator()(const std::unique_ptr<student_t>& first, const std::unique_ptr<student_t>& second) const {
		switch (m_method) {
		case name:
			if (std::string(first->get_name()) < std::string(second->get_name()))
				return true;
			break;
		case age:
			if (first->get_age() < second->get_age())
				return true;
			break;
		case year:
			if (first->get_year() < second->get_year())
				return true;
			break;
		case group:
			if (first->get_year() > second->get_year())
				return true;
			break;
		}
		return false;
	}

private:
	method m_method;
};