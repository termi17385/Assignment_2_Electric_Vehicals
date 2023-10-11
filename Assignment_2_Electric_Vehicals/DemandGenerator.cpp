#include <stdlib.h>
#include <iostream>
#include <iomanip>

#include "DemandGenerator.h"
#include "Constants.h"
#include "Math.h"
#include <fstream>
using namespace std;

int DemandGenerator::getVehicleId()				{ return vehicleId++; }
int DemandGenerator::getRandomDestination()		{ return Math::randomRange(1, NUM_CITIES); }
int DemandGenerator::getRandomCapacity()		{ return Math::randomRange(MIN_CAPACITY, MAX_CAPACITY); }
int DemandGenerator::getRemainRange(int _cap)	{ return Math::randomRange(MIN_CAPACITY, _cap); }

std::string DemandGenerator::getDemand()
{
	int vehicleId		= getVehicleId();
	int destinationId	= getRandomDestination();
	int capacityRange	= getRandomCapacity();
	int remainRange		= getRemainRange(capacityRange);


	std::string demand				= "["
		+ to_string(vehicleId)		+ ','
		+ to_string(destinationId)	+ ','
		+ to_string(capacityRange)	+ ','
		+ to_string(remainRange)	+ ']';

	return demand;
}

void DemandGenerator::writeDemands(int _amountOfDemands)
{
	std::ofstream chargingDemands(DEMANDS_PATH);

	if (chargingDemands.is_open())
	{
		chargingDemands.flush(); 
		for (int i = 0; i < _amountOfDemands; i++)
		{
			std::string demand = getDemand();

			chargingDemands << demand << endl;
		}
		s
		chargingDemands.close();

		cout << endl << "Demands Successfully Written To: " << "dadw" << endl;
	}
	else
	{
		cout << endl << "ERROR OPENING FILE" << endl;
	}
}