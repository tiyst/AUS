#pragma once
#include "Locations.h"

class Order {

private:
	float weight;
	LOCATION from;
	LOCATION to;
	bool isCancelable();

public:
	Order(float weight, LOCATION from, int distFrom, LOCATION to, int distTo);
	~Order();
};