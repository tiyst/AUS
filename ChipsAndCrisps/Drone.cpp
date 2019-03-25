#include "Drone.h"

Drone::Drone(int serialNumber, DRONE_TYPE type, Calendar *cal) {
	this->serialNumber = serialNumber;
	this->type = type;
	this->cal = cal;
	this->charge = 100;
	timeAdded = cal->getDate();
	initDrone();
}

Drone::~Drone() {
}


void Drone::initDrone() {
	switch (type) {
		case TYPE_ONE:
			capacity = 2.0;
			speed = 80;
			flightDuration = 40;
			minutesPerTenCharge = 3;
			break;

		case TYPE_TWO:
			capacity = 5.0;
			speed = 40;
			flightDuration = 60;
			minutesPerTenCharge = 5;
			break;
	}
}

std::string Drone::toString() {
	return
		" Serial number: " + std::to_string(serialNumber) +
		" typed " + std::to_string(type) +
		" added on: " + cal->dateToString(timeAdded) +
		" Flew for " + std::to_string(flightHours) + " hours and "
		" carried " + std::to_string(ordersDone) + " orders\n";

}
