#include <iostream>
#include "classes.h"

int main() {

	truck_t truck(40, 100);
	truck.print_data();

	military_airplane_t airplane(100, 400);
	airplane.print_data();

	return 0;
}