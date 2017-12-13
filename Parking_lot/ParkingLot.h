#pragma once

#include "ParkingLevel.h"

using namespace std;

class ParkingLot
{
public:
	ParkingLot(unsigned int levels, unsigned int rows, unsigned int row_size);
	~ParkingLot();

	bool parkVehicle(Vehicle *vehicle);
	static void generateRandomLayout(ParkingLot &pl);
	void printInfo();

private:
	const unsigned int level_size_;
	vector<ParkingLevel> levels_;

};

