#include "ChargingAllocation.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "DemandGenerator.h"

/* 
I hold a copy of this assignment that I can produce if the original is lost or damaged.
I hereby certify that no part of this assignment has been copied from any other student’s work or
from any other source except where due acknowledgement is made in the assignment. No part
of this assignment has been written/produced for me by another person except where such
collaboration has been authorised by the subject lecturer concerned. */

void generateDemands();

int main()
{
	generateDemands();

	// Initialise Charging Allocations
	std::cout << std::endl;
	std::cout << "Initialising Charging Allocations: " << std::endl;

	ChargingAllocation c;
	c.init();
	
	// Display all Vehicles
	std::cout << std::endl;
	c.displayAllVehiclesInformation();
	std::cout << std::endl;
	
	// Display all charging stations
	std::cout << "Charging Station Information: " << std::endl;
	c.displayAllStationQueues(NUM_CITIES, false);
	std::cout << std::endl;
	
	// Display all vehicles recharge stops
	std::cout << "Initial charging allocation ..." << std::endl;
	c.determineRechargeStations();
	c.displayAllQueuedVehicles();
	std::cout << std::endl;
	std::cout << std::endl;
	
	// Display Charging Queues
	c.displayAllStationQueues();

	std::cout << std::endl;
	std::cout << "Overall Waiting Hours: " << c.calculatOverallWaitTime();
	std::cout << std::endl;
	system("pause");

	return 0;
}

void generateDemands()
{
	// Write to Charging Demands
	DemandGenerator d;

	srand(time(nullptr));

	int amountOfDemands = Math::randomRange(MIN_DEMANDS, MAX_DEMANDS);

	std::cout << "Generating " << (amountOfDemands + 1) << " Demands" << std::endl;

	d.writeDemands(amountOfDemands);

	char ans = ' ';

	std::cout << std::endl;
	std::cout << "Print file location? (Y/N)" << std::endl;
	std::cin >> ans;

	if (ans == 'Y' || ans == 'y') d.displayFileLocation();
}