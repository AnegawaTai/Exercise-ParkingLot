#include "stdafx.h"
#include "ParkingSpot.h"

#include <iostream>
#include <string>

using namespace std;

ParkingSpot::ParkingSpot(unsigned int floor, unsigned int row, int pos, VehicleSize v_size): floor_(floor), row_(row), pos_(pos), size_(v_size)
{
	availability_ = true;
}


ParkingSpot::~ParkingSpot()
{
}

void ParkingSpot::printSpotInfo()
{
	string state;
	if (availability_)
		state = "(E)";
	else
		state = "(F)";
	switch (size_)
	{
	case Small:
		cout << "M";
		state += " ";
		break;
	case Compact:
		cout << "C";
		state += "- ";
		break;
	case Large:
		cout << "L";
		state += "-- ";
		break;
	default:
		break;
	}
	cout << state;
}
