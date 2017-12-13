#include "stdafx.h"
#include "Car.h"


Car::Car()
{
	spots_needed_[Small] = 0;
	spots_needed_[Compact] = 1;
	spots_needed_[Large] = 1;
}


Car::~Car()
{
}
