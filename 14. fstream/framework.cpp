#include "framework.h"

#include <algorithm>

#include "class.h"

#include <iostream>
#include <format>
#include <fstream>

#define format(x, ...)		std::cout << std::##format(x, ##__VA_ARGS__)
#define valid_option(x) (x > 0 && x < 9)


namespace fw {

	bool			g_initialized	= false;
	const char*		g_filename		= nullptr;
	soldier_t*		g_soldiers		= nullptr;
	int				g_count			= 0;
	enum show_spec {
	def, month, oldest_male, last_name};

	bool init(const char* filename) {
		g_filename = filename;

		g_initialized = true;
		return true;
	}

	bool load_file() {
		std::ifstream file(g_filename, std::ios::binary | std::ios::ate);
		if (file.fail()) {
			format("couldn't open the file!\n");
			file.close();
			return false;
		}

		size_t file_size = file.tellg();
		if (file_size % sizeof(soldier_t)) {
			format("invalid file size!\n");
			file.close();
			return false;
		}
		file.seekg(0);
		g_count = file_size / sizeof(soldier_t);
		delete[] g_soldiers;
		g_soldiers = new soldier_t[g_count];
		file.read((char*)g_soldiers, file_size);
		file.close();
		return true;
	}

	bool save_file() {
		if (!g_soldiers) {
			format("missing data!\n");
			return false;
		}

		std::ofstream file(g_filename, std::ios::out | std::ios::binary);
		if (file.fail()) {
			format("couldn't open the file!");
			file.close();
			return false;
		}

		file.seekp(0);
		file.write((char*)g_soldiers, g_count * sizeof(soldier_t));
		file.close();
		return true;
	}

	void enter_data() {
		format("Enter the number of soldiers: ");
		std::cin >> g_count;
		if (g_count < 1) {
			g_count = 0;
			return;
		}

		delete[] g_soldiers;
		g_soldiers = new soldier_t[g_count];

		char	name[32];
		char	surname[32];
		int		day_of_birth;
		int		month_of_birth;
		int		year_of_birth;
		int gender;

		for (int i = 0; i < g_count; i++) {
			format("name: ");
			std::cin >> name;
			format("surname: ");
			std::cin >> surname;
			format("day of birth: ");
			std::cin >> day_of_birth;
			format("month of birth: ");
			std::cin >> month_of_birth;
			format("year of birth: ");
			std::cin >> year_of_birth;
			format("gender (0 - male, 1 - female): ");
			std::cin >> gender;

			g_soldiers[i] = soldier_t(name, surname, day_of_birth, month_of_birth, year_of_birth, (gender_e)gender);
		}
	}

	void show_data(show_spec specifier = def, int param = 0) {
		format("{:~^53}\n", " DATA ");
		format(" # | {:^10} | {:^10} | Gender | Date of Birth\n", "Name", "Surname");
		format("{:-^53}\n", "");
		soldier_t* result = nullptr;
		switch (specifier) {
		case def:
			for (int i = 0; i < g_count; i++)
				format("{:2} | {:^10} | {:^10} | {:^6} | {:^13}\n"
					, i, g_soldiers[i].get_name(), g_soldiers[i].get_surname(), g_soldiers[i].get_gender() ? "F" : "M", g_soldiers[i].get_date_of_birth());
			break;
		case month:
			for (int i = 0; i < g_count; i++)
				if (g_soldiers[i].get_month_of_birth() == param)
				format("{:2} | {:^10} | {:^10} | {:^6} | {:^13}\n"
					, i, g_soldiers[i].get_name(), g_soldiers[i].get_surname(), g_soldiers[i].get_gender() ? "F" : "M", g_soldiers[i].get_date_of_birth());
			break;
		case oldest_male:
			for (int i = 0; i < g_count; i++) {
				if (g_soldiers[i].get_gender() != male)
					continue;
				if (!result) {
					result = &g_soldiers[i];
					continue;
				}
				if (g_soldiers[i].get_year_of_birth() <= result->get_year_of_birth())
					if (g_soldiers[i].get_month_of_birth() <= result->get_month_of_birth())
						if (g_soldiers[i].get_day_of_birth() <= result->get_day_of_birth())
							result = &g_soldiers[i];
			}
			if (!result)
				break;
			format("{:2} | {:^10} | {:^10} | {:^6} | {:^13}\n"
				, 0, result->get_name(), result->get_surname(), result->get_gender() ? "F" : "M", result->get_date_of_birth());


			break;
		case last_name: 
			for (int i = 0; i < g_count; i++)
				if (g_soldiers[i].get_surname()[0] == param)
					format("{:2} | {:^10} | {:^10} | {:^6} | {:^13}\n"
						, i, g_soldiers[i].get_name(), g_soldiers[i].get_surname(), g_soldiers[i].get_gender() ? "F" : "M", g_soldiers[i].get_date_of_birth());
			break;
		default: ;
		}
	}

	void sort_data() {
		for (int i = 0; i < g_count; i++) {
			for (int j = i; j < g_count; j++) {
				if (strcmp(g_soldiers[j].get_name(), g_soldiers[i].get_name()) < 0)
					std::swap(g_soldiers[i], g_soldiers[j]);
			}
		}
	}

	void launch_option(const int option) {
		if (!valid_option(option)) 
			return;
		system("cls");

		switch (option) {
		case 1:
			load_file();
			break;
		case 2:
			save_file();
			break;
		case 3:
			enter_data();
			break;
		case 4:
			show_data();
			break;
		case 5:
			sort_data();
			break;
		case 6:
			format("Enter the index of the month: ");
			int param_i;
			std::cin >> param_i;
			show_data(month, param_i);
			break;
		case 7:
			show_data(oldest_male);
			break;
		case 8:
			format("Enter the character: ");
			char param_c;
			std::cin >> param_c;
			show_data(last_name, param_c);
			break;
		}

		system("pause");
	}

	void mainloop() {
		if (!g_initialized)
			return;

		int option = 0;

		do {
			format(
				"1) load data from file\n"
				"2) save data to file\n"
				"3) enter data\n"
				"4) show data\n"
				"5) sort data in alphabet order\n"
				"6) show data: people born in chosen month\n"
				"7) show data: the oldest male\n"
				"8) show data: people, whose last name start with a chosen letter\n"
				"0) exit the program\n"
			);
			std::cin >> option;
			std::cin.clear();
			launch_option(option);
			system("cls");
		} while (option);
	}
}