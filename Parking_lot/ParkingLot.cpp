#include "stdafx.h"
#include "ParkingLot.h"

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 

ParkingLot::ParkingLot(unsigned int levels, unsigned int rows, unsigned int row_size):level_size_(levels)
{
	for (int i = 0; i < level_size_; i++)
	{
		ParkingLevel current_floor(i, rows, row_size);
		levels_.push_back(current_floor);
	}
}


ParkingLot::~ParkingLot()
{
}

bool ParkingLot::parkVehicle(Vehicle *vehicle)
{
	int row, start_pos, end_pos;
	for (int i = 0; i < level_size_; i++)
	{
		if (levels_[i].parkVehicle(vehicle, row, start_pos, end_pos))
		{
			vehicle->ParkVehicle(i, row, start_pos, end_pos);
			return true;
		}
	}
	return false;
}

void ParkingLot::generateRandomLayout(ParkingLot &pl)
{
	std::srand(std::time(0));
	for (int i = 0; i < pl.level_size_; i++)
	{
		ParkingLevel& current_floor = pl.levels_[i];
		unsigned int row_size = current_floor.getRowSize();
		//cout << "Row size: " << row_size;
		int left_spots = row_size;
		int large = 0, compact = 0, small = 0;
		if(left_spots > Large)
		{ 
			large = (rand() % (left_spots / Large + 1));
			left_spots -= large * Large;
		}
		if(left_spots > Compact)
		{ 
			compact = (rand() % (left_spots / Compact + 1));
			left_spots -= compact * Compact;
		}
		if (left_spots > Small)
		{
			small = left_spots;
		}
		//cout << "Large: " << large
		//	<< " Compact: " << compact
		//	<< " Motorcycle: " << small << endl;
		current_floor.setSpots(large, compact, small);
	}

	pl.printInfo();
}

void ParkingLot::printInfo()
{
	cout << "Parking Lot state: " << endl;
	for (int i = 0; i < level_size_; i++)
	{
		levels_[i].printLevelInfo();
	}
}
