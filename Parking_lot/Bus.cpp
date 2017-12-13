#include "stdafx.h"
#include "Bus.h"


Bus::Bus()
{
	spots_needed_[Small] = 0;
	spots_needed_[Compact] = 0;
	spots_needed_[Large] = 5;
}


Bus::~Bus()
{
}
