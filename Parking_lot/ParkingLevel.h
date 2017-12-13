#pragma once

#include <vector>
#include "ParkingSpot.h"

class ParkingLevel
{
public:
	ParkingLevel(unsigned int floor, unsigned int rows, unsigned int row_size);
	~ParkingLevel();

	unsigned getRows() { return rows_; }
	unsigned getRowSize() { return row_size_; }
	void setSpots(unsigned int large, unsigned int compact, unsigned int small);
	bool parkVehicle(Vehicle *vehicle, int& row, int& start_pos, int& end_pos);
	void changeSpotState(bool availability, int row, int start, int end);
	void printLevelInfo();

private:
	const unsigned int rows_;
	const unsigned int row_size_;

	unsigned int floor_;
	vector <vector<ParkingSpot> > spots_;
};

