#pragma once
#include <string>
#include <ctime>
#include "Calendar.h"

class Vehicle {
public:
	Vehicle(std::string &spz, int capacity, int costs, Calendar *cal);
	~Vehicle();

	std::string toString();
private:
	std::string spz;
	int capacity; //in tons
	int costs;
	Calendar *cal;
	time_t dateAdded;
};