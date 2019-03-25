#include <iostream>
#include <string>
#include "structures/list/array_list.h"
#include "structures/priority_queue/priority_queue.h"
#include "structures\heap_monitor.h"
#include "Vehicle.h"
#include "Drone.h"
#include "Warehouse.h"
#include "Order.h"

using namespace structures;

int inputChoice();
void testingData();
void initWarehouses();
void cleanMemory();
void removeStructure(Structure *st);

void addVehicle();
void addDrone();
bool addOrder();
void writeVehicles();
void writeMenu();
void writeDrones();
void writeWarehouses();
Warehouse* findWarehouse();

Calendar *cal;
ArrayList<Vehicle*> *vehicles;
//ArrayList<Drone*> *drones;
ArrayList<Warehouse*> *warehouses;
PriorityQueue<PriorityQueueItem<Order*>> *orders;
//PriorityQueueItem<Calendar*> pqi = PriorityQueueItem(Calendar());

void cleanMemory() {
	for (Vehicle* vh : *vehicles) {
		delete vh;
	}
	/*for (Drone* dr : *drones) {
		dr->~Drone();
	}*/
	for (Warehouse* wh : *warehouses) {
		delete wh;
	}
	delete cal;
	delete vehicles;
	//delete drones;
	delete warehouses;
	delete orders;

	/*removeStructure(vehicles);
	removeStructure(drones);
	removeStructure(warehouses);
	removeStructure(orders);*/
}

void removeStructure(Structure *st) {
	for (int i = 0; i < st->size() - 1; i++) {
		Array<Calendar> *ar = new Array<Calendar>(4);
	}
}

int main() {
	initHeapMonitor();
	
	cal = new Calendar();
	vehicles = new ArrayList<Vehicle*>();
	//drones = new ArrayList<Drone*>();
	warehouses = new ArrayList<Warehouse*>();
	initWarehouses();
	testingData();

	writeMenu();

	while (inputChoice() != 0) { //testing redo
		writeMenu();
	}

	cleanMemory();
}

int inputChoice() {
	int choice;
	std::cin >> choice;
	switch (choice) {
	case 1:
		cal->passHour();
		break;
	case 11:
		cal->passMinute();
		break;
	case 2:
		addVehicle();
		break;
	case 21:
		writeVehicles();
		break;
	case 3:
		addDrone();
		break;
	case 31:
		writeDrones();
		break;
	case 4:
		addOrder();
		break;
	}

	return choice;
}

void writeMenu() {
	std::cout << cal->toString() << std::endl;
	std::cout << "1. Pass Hour\t 11. Pass Minute \n" 
			  << "2. Add Vehicle\t 21. Write Vehicles\n"
			  << "3. Add Drone\t 31. Write Drones\n"
			  << "4. Add Order\n"
			  << "\n0. End\n";
	
	std::cout << std::endl;
}


void addVehicle() {
	std::string spz;
	int capacity, costs;
	std::cout << "Insert SPZ (5 characters)\n";
	std::cin >> spz;
	if (spz.length() != 5) {
		std::cout << "SPZ needs 5 characters\n";
		return;
	}

	std::cout << "Insert capacity\n";//std::is_digit()
	std::cin >> capacity;
	std::cout << "Insert costs\n";
	std::cin >> costs;
	
	vehicles->add(new Vehicle(spz, capacity,costs, cal));
}

void writeVehicles() {
	for (Vehicle *vehicle : *vehicles) {
		std::cout << vehicle->toString() << "\n";
	}
}


void testingData() {
	//Vehicles
	vehicles->add(new Vehicle((std::string)"hello", 14, 9, cal));
	vehicles->add(new Vehicle((std::string)"world", 32, 11, cal));
	vehicles->add(new Vehicle((std::string)"nibba", 20, 12, cal));

	//Drones
	warehouses->operator[](0)->addDrone(new Drone(1, (Drone::DRONE_TYPE)1, cal));
	warehouses->operator[](0)->addDrone(new Drone(2, (Drone::DRONE_TYPE)2, cal));
	warehouses->operator[](0)->addDrone(new Drone(3, (Drone::DRONE_TYPE)1, cal));
	std::cout << warehouses->operator[](0)->getName();
}

void addDrone() {
	int serialNumber, type = 0;
	std::cout << "Insert serial number\n";
	std::cin >> serialNumber;

	std::cout << "Is the drone type 1 or type 2?\n";
	std::cin >> type;
	while(type > 2 && type < 1) {
		std::cin >> type;
	}
	
	switch (type) {
	case 1:	
		break;
	case 2:
		break;
	default:
		std::cout << "Wrong drone type, check it out";
		break;
	}

	std::cout << "What is this drones home warehouse?\n";
	Warehouse *wr = findWarehouse();
	if (wr != nullptr) {
		wr->addDrone(new Drone(serialNumber, (Drone::DRONE_TYPE)type, cal));
	} else {
		std::cout << "\nError adding drone! (no warehouse selected)\n";
	}
}

bool addOrder() {
	return true;
}

void writeDrones() {
	Warehouse *wrh = findWarehouse();
	ArrayList<Drone*> *drones = wrh->getDrones();

	for (int i = 0; i < drones->size(); i++) {
		std::cout << drones->operator[](i)->toString() << "\n";
	}
}

void writeWarehouses() {
	for (int i = 1; i <= warehouses->size(); i++) {
		std::cout << warehouses->operator[](i-1)->getName()
			<< ((i % 4) ? "\t" : "\n");
	}
}

Warehouse* findWarehouse() {
	writeWarehouses();
	std::string wrh;
	std::cout << "Write which warehouse you want to choose.\n";
	std::cin >> wrh;

	for (Warehouse *wr : *warehouses) {
		if (wrh.compare(wr->getName()) == 0) {
			return wr;
		}
	}
	return nullptr;
}

void initWarehouses() {
	for (int i = 0; i < (LOCATION)MI; i++) {
		warehouses->add(new Warehouse(LOCATION::ZA, "ZA"));
	}
	warehouses->add(new Warehouse(LOCATION::ZA, "ZA"));
	warehouses->add(new Warehouse(LOCATION::MA, "MA"));
	warehouses->add(new Warehouse(LOCATION::BA, "BA"));
	warehouses->add(new Warehouse(LOCATION::TT, "TT"));
	warehouses->add(new Warehouse(LOCATION::NR, "NR"));
	warehouses->add(new Warehouse(LOCATION::KN, "KN"));
	warehouses->add(new Warehouse(LOCATION::LV, "LV"));
	warehouses->add(new Warehouse(LOCATION::TN, "TN"));
	warehouses->add(new Warehouse(LOCATION::PD, "PD"));
	warehouses->add(new Warehouse(LOCATION::CA, "CA"));
	warehouses->add(new Warehouse(LOCATION::MT, "MT"));
	warehouses->add(new Warehouse(LOCATION::KA, "KA"));
	warehouses->add(new Warehouse(LOCATION::ZV, "ZV"));
	warehouses->add(new Warehouse(LOCATION::LC, "LC"));
	warehouses->add(new Warehouse(LOCATION::BB, "BB"));
	warehouses->add(new Warehouse(LOCATION::RA, "RA"));
	warehouses->add(new Warehouse(LOCATION::NO, "NO"));
	warehouses->add(new Warehouse(LOCATION::LM, "LM"));
	warehouses->add(new Warehouse(LOCATION::PP, "PP"));
	warehouses->add(new Warehouse(LOCATION::SL, "SL"));
	warehouses->add(new Warehouse(LOCATION::PO, "PO"));
	warehouses->add(new Warehouse(LOCATION::HE, "HE"));
	warehouses->add(new Warehouse(LOCATION::SN, "SN"));
	warehouses->add(new Warehouse(LOCATION::KE, "KE"));
	warehouses->add(new Warehouse(LOCATION::MI, "MI"));
}

