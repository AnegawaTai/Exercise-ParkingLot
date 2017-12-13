#include "stdafx.h"
#include "Vehicle.h"

#include <iostream>
#include <string>

Vehicle::Vehicle()
{
	is_parking_ = false;
	floor_ = -1;
	row_ = -1;
	start_pos_ = -1;
	end_pos_ = -1;
}


Vehicle::~Vehicle()
{
}

void Vehicle::ParkVehicle(int floor, int row, int start_pos, int end_pos)
{
	is_parking_ = true;
	floor_ = floor;
	row_ = row;
	start_pos_ = start_pos;
	end_pos_ = end_pos;
}

void Vehicle::RemoveVehicle()
{
	is_parking_ = false;
	floor_ = -1;
	row_ = -1;
	start_pos_ = -1;
	end_pos_ = -1;
}

void Vehicle::printParkingInfo()
{
	if(is_parking_)
		cout << "parking at floor: " << floor_ 
		<< " row: " << row_ 
		<< " from: " << start_pos_ << " to: " << end_pos_<< endl;
	else
		cout << "Cannot find avaliable spot." << endl;
}
