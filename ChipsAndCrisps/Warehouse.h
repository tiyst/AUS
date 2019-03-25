#pragma once
#include "Locations.h"
#include "Drone.h"
#include "structures/list/array_list.h"
#include <string>

using namespace structures;

class Warehouse {
private:
	LOCATION location;
	std::string name;
	ArrayList<Drone*> *drones;

public:
	Warehouse(LOCATION loc, std::string name);
	~Warehouse();

	ArrayList<Drone*>* getDrones();
	void addDrone(Drone *drone);
	std::string getName();
};