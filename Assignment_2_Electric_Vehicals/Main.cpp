#include "ChargingAllocation.h"
#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	// weird bug occured
	ChargingAllocation chargingAllocation;
	chargingAllocation.init();
	
	chargingAllocation.determineRechargeStations();
	
	//chargingAllocation.displayAllStationQueues(NUM_CITIES, false);

	chargingAllocation.displayAllStationQueues();
	chargingAllocation.displayAllQueuedVehicles();
	return 0;
}