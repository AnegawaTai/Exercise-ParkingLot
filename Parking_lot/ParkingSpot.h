#pragma once

#include "Vehicle.h"

class ParkingSpot
{
public:
	ParkingSpot(unsigned int floor, unsigned int row, int pos, VehicleSize v_size);
	~ParkingSpot();

	bool isAvailability() { return availability_; }
	void setAvailability(bool a) { availability_ = a; }
	void printSpotInfo();
	VehicleSize getSpotType() { return size_; }

private:
	unsigned int floor_;
	unsigned int row_;
	unsigned int pos_;
	VehicleSize size_;
	bool availability_;

};

