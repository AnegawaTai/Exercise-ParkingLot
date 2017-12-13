#include "stdafx.h"
#include "ParkingLevel.h"

#include <iostream>
#include <string>

ParkingLevel::ParkingLevel(unsigned int floor, unsigned int rows, unsigned int row_size): 
	floor_(floor), rows_(rows), row_size_(row_size)
{
}


ParkingLevel::~ParkingLevel()
{
}

void ParkingLevel::setSpots(unsigned int large, unsigned int compact, unsigned int small)
{
	for (int i = 0; i < rows_; i++)
	{
		vector <ParkingSpot> current_row;
		int pos = 0;
		for (int j = 0; j < small; j++)
		{
			ParkingSpot new_spot(floor_, i, pos++, Small);
			current_row.push_back(new_spot);
		}
		for (int j = 0; j < compact; j++)
		{
			ParkingSpot new_spot(floor_, i, pos++, Compact);
			current_row.push_back(new_spot);
		}
		for (int j = 0; j < large; j++)
		{
			ParkingSpot new_spot(floor_, i, pos++, Large);
			current_row.push_back(new_spot);
		}


		//cout << current_row.size() << endl;
		spots_.push_back(current_row);
	}
	//cout << spots_.size() << endl;
}

bool ParkingLevel::parkVehicle(Vehicle * vehicle, int & row, int& start_pos, int& end_pos)
{
	map<VehicleSize, int>& spots_needed = vehicle->getSpotsNeeded();
	for (int i = 0; i < rows_; i++)
	{
		int count = 0;
		int start_spot = -1;
		vector<ParkingSpot> current_row = spots_[i];
		for (int j = 0; j < current_row.size(); j++)
		{
			if (current_row[j].isAvailability())
			{
				VehicleSize spot_type = current_row[j].getSpotType();
				if (spots_needed[spot_type] > 0)
				{
					if(count == 0)
						start_spot = j;
					count++;
					if (count == spots_needed[spot_type])
					{
						row = i;
						start_pos = start_spot;
						end_pos = j;
						changeSpotState(false, row, start_pos, end_pos);
						return true;
					}
				}
				else
					count = 0;
			}
			else
				count = 0;
		}
	}
	row = -1;
	start_pos = -1;
	end_pos = -1;
	return false;
}

void ParkingLevel::changeSpotState(bool availability, int row, int start, int end)
{
	for (int i = start; i <= end ; i++)
	{
		spots_[row][i].setAvailability(availability);
	}
}

void ParkingLevel::printLevelInfo()
{
	cout << "Level " << floor_ << ": " << endl;
	//cout << spots_.size() << endl;
	for (int i = 0; i < spots_.size(); i++)
	{
		vector <ParkingSpot>& current_row = spots_[i];
		//cout << current_row.size() << endl;
		for (int j = 0; j < current_row.size(); j++)
		{
			current_row[j].printSpotInfo();
		}
		cout << endl;
	}
	cout << endl;
}
