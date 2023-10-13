#pragma once
#include <string>

const std::string DEMANDS_PATH = "ChargingDemands.txt";

class DemandGenerator
{
private:

	int vehicleId = 200;

	int getVehicleId();

	int getRandomDestination();

	int getRandomCapacity();

	int getRemainRange(int _cap);

	std::string getDemand();

public:

	void writeDemands(int _amountOfDemands);

	static void displayFileLocation();
};