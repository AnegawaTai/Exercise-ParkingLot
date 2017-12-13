// Parking_lot.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ParkingLot.h"
#include <iostream>
#include <string>

#include "Motorcycle.h"
#include "Car.h"
#include "Bus.h"

int main()
{
	ParkingLot pl(3, 3, 30);
	ParkingLot::generateRandomLayout(pl);

	Vehicle *v = new Bus;

	pl.parkVehicle(v);
	v->printParkingInfo();
	pl.printInfo();
	
    return 0;
}

