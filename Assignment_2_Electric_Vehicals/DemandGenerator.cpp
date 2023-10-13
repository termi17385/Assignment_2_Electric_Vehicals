#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <filesystem>
#include <fstream>

#include "DemandGenerator.h"
#include "Constants.h"
#include "Math.h"

using namespace std;

namespace fs = filesystem;

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
		
		chargingDemands.close();

		cout << endl << "File Successfully Written To" << endl;
	}
	else
	{
		cout << endl << "ERROR OPENING FILE" << endl;
	}
}

void DemandGenerator::displayFileLocation()
{
	fs::path workingDirectory = fs::current_path();

	cout << endl << "Charging Demands Location:\n\n" << workingDirectory << "\\" << DEMANDS_PATH << endl;
}