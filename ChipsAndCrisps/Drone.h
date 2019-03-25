#pragma once
#include <string>
#include "Calendar.h"

class Drone {
public:
	enum DRONE_TYPE {
		TYPE_ONE=1,
		TYPE_TWO=2
	};

	Drone(int serialNumber ,DRONE_TYPE type, Calendar *cal);
	~Drone();
	std::string toString();

private:
	Calendar *cal;
	DRONE_TYPE type;
	int serialNumber;
	float capacity;
	int speed;
	int flightDuration;
	int charge;
	int minutesPerTenCharge;

	int flightHours;
	int ordersDone;
	time_t timeAdded;


	void initDrone();
};