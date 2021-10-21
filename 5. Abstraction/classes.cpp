#include "classes.h"

constexpr double FuelPrice = 94;		// [$$$] / L


//	~~~ TRUCK ~~~
double truck_t::get_fuel_consumption() {
	return m_dbEngineConsumption;
}
const double& truck_t::get_mass(){
	return m_dbMass;
}
void truck_t::print_data() {
	printf(
		"Truck [0x%p]\n"
		"- Mass: %f (tons)\n"
		"- Number of seats: %d\n"
		"- Engine consumption: %f (L/km)\n\n"
		, this, m_dbMass, m_cSeats, m_dbEngineConsumption);
}

//	~~~ PASSENGER CAR ~~~
double passenger_car_t::get_fuel_consumption() {
	return m_dbEngineConsumption;
}
const double& passenger_car_t::get_mass() {
	return m_dbMass;
}
void passenger_car_t::print_data() {
	printf(
		"Passenger Car [0x%p]\n"
		"- Mass: %f (tons)\n"
		"- Number of seats: %d\n"
		"- Engine consumption: (L/km)\n\n"
		, this, m_dbMass, m_cSeats, m_dbEngineConsumption);
}

//	~~~ PASSENGER AIRPLANE ~~~
double passenger_airplane_t::get_fuel_consumption() {
	return m_dbEngineConsumption * m_cEngines;
}
const double& passenger_airplane_t::get_mass() {
	return m_dbMass;
}
double passenger_airplane_t::get_travel_cost() {
	return get_fuel_consumption() * FuelPrice * 1.25;
}
void passenger_airplane_t::print_data() {
	printf(
		"Passenger Airplane [0x%p]\n"
		"- Mass: %f (tons)\n"
		"- Number of seats: %d\n"
		"- Engine consumption: %f (L/km)\n"
		"- Number of engines: %d\n"
		"- Travel cost: %f ($$$/km)\n\n"
		, this, m_dbMass, m_cSeats, m_dbEngineConsumption, m_cEngines, get_travel_cost());
}

//	~~~ MILITARY AIRPLANE ~~~
double military_airplane_t::get_fuel_consumption() {
	return m_dbEngineConsumption * m_cEngines;
}
const double& military_airplane_t::get_mass() {
	return m_dbMass;
}
double military_airplane_t::get_travel_cost() {
	return get_fuel_consumption() * FuelPrice;
}
void military_airplane_t::print_data() {
	printf(
		"Military Airplane [0x%p]\n"
		"- Mass: %f (tons)\n"
		"- Number of seats: %d\n"
		"- Engine consumption: %f (L/km)\n"
		"- Number of engines: %d\n"
		"- Travel cost: %f ($$$/km)\n\n"
		, this, m_dbMass, m_cSeats, m_dbEngineConsumption, m_cEngines, get_travel_cost());
}