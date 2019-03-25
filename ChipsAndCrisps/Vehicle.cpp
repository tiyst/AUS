#include "Vehicle.h"

Vehicle::Vehicle(std::string &spz, int capacity, int costs, Calendar *cal){
	this->spz = spz;
	this->capacity = capacity;
	this->costs = costs;
	this->cal = cal;
	this->dateAdded = cal->getDate();
}

Vehicle::~Vehicle() {
}

std::string Vehicle::toString() {
	return "SPZ: " + spz
		+ " Capacity: " + std::to_string(capacity)
		+ " Added on: " + cal->dateToString(this->dateAdded);
}
