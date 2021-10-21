#pragma once
#include <iostream>

class vehicle_t {
public:
	virtual double get_fuel_consumption() = 0;
	virtual const double& get_mass() = 0;

	virtual void print_data() = 0;
};

class car_t : public vehicle_t {
public:
	car_t(double _mass, double _engconsump, int _seats = 4)
		: m_dbMass(_mass), m_dbEngineConsumption(_engconsump), m_cSeats(_seats) {};

protected:
	double m_dbMass;
	double m_dbEngineConsumption;
	int m_cSeats;
};

class truck_t : public car_t {
public:
	truck_t(double _mass, double _engconsump, int _seats = 2)
		: car_t(_mass, _engconsump, _seats) {
		printf("/!\\ Truck created! (mass: %f, consump: %f, seats: %d)\n", _mass, _engconsump, _seats);
	};

	double get_fuel_consumption() override;
	const double& get_mass() override;

	void print_data() override;
};

class passenger_car_t : public car_t {
public:
	passenger_car_t(double _mass, double _engconsump, int _seats = 4)
		: car_t(_mass, _engconsump, _seats) {
		printf("/!\\ Passenger car created! (mass: %f, consump: %f, seats: %d)\n", _mass, _engconsump, _seats);
	};

	double get_fuel_consumption() override;
	const double& get_mass() override;

	void print_data() override;
};

class airplane_t : public vehicle_t {
public:
	airplane_t(double  _mass, double _engconsump, int _seats = 100, int _engines = 2)
		: m_dbMass(_mass), m_dbEngineConsumption(_engconsump), m_cSeats(_seats), m_cEngines(_engines) {};

	virtual double get_travel_cost() = 0;

protected:
	double m_dbMass;
	double m_dbEngineConsumption;
	int m_cSeats;
	int m_cEngines;
};

class passenger_airplane_t : public airplane_t {
public:
	passenger_airplane_t(double  _mass, double _engconsump, int _seats = 100, int _engines = 2)
		: airplane_t(_mass, _engconsump, _seats, _engines) {
		printf("/!\\ Passenger airplane created! (mass: %f, consump: %f, seats: %d, engines: %d)\n", _mass, _engconsump, _seats, _engines);
	};

	double get_fuel_consumption() override;
	const double& get_mass() override;
	double get_travel_cost() override;

	void print_data() override;
};

class military_airplane_t : public airplane_t {
public:
	military_airplane_t(double  _mass, double _engconsump, int _seats = 70, int _engines = 2)
		: airplane_t(_mass, _engconsump, _seats, _engines) {
		printf("/!\\ Military airplane created! (mass: %f, consump: %f, seats: %d, engines: %d)\n", _mass, _engconsump, _seats, _engines);
	};

	double get_fuel_consumption() override;
	const double& get_mass() override;
	double get_travel_cost() override;

	void print_data() override;
};