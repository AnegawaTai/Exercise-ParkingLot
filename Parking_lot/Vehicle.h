#pragma once

#include <map>

using namespace std;

enum VehicleSize { Small = 1, Compact = 2, Large = 3};

class Vehicle
{
public:
	Vehicle();
	virtual ~Vehicle();
	map<VehicleSize, int>& getSpotsNeeded() { return spots_needed_; }
	void ParkVehicle(int floor, int row, int start_pos, int end_pos);
	void RemoveVehicle();
	void printParkingInfo();


protected: 
	map<VehicleSize, int> spots_needed_;
	double fee_;
	bool is_parking_;
	int floor_;
	int row_;
	int start_pos_;
	int end_pos_;
};

