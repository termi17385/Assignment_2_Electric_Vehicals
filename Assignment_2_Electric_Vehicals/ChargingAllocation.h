#pragma once

#include "Vehical.h"

#include <vector>
#include <string>

class ChargingAllocation
{
private:

	std::vector<Vehical> vehicles;

	std::vector<int> convertLineToIntArray(std::string _line);

public:


};