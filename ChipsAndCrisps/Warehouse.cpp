#include "Warehouse.h"


Warehouse::Warehouse(LOCATION loc, std::string name) {
	this->location = loc;
	this->name = name;
	this->drones = new ArrayList<Drone*>();
}

Warehouse::~Warehouse() {
	for (Drone* dr : *drones) {
		delete dr;
	}
	delete drones;
}

void Warehouse::addDrone(Drone *drone) {
	drones->add(drone);
}

ArrayList<Drone*>* Warehouse::getDrones() {
	return drones;
}

std::string Warehouse::getName() {
	return this->name;
}
