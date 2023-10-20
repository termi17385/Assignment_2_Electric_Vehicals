#include "Vehical.h"
#include "Constants.h"
#include "ChargingStation.h"
#include <iostream>
#include <iomanip>

void Vehical::reset(int _newCity)
{
	currentCityId = _newCity;
	remainRange = capacityRange;
}

int Vehical::calculateFarthestCity(int _remaining, int _currentCity)
{
	int next = _currentCity;
	
	if (next + 1 > NUM_CITIES - 1) return NUM_CITIES - 1;
	
	int distance = distanceMap[next + 1];

	if (_remaining < distance) return next;
	
	return calculateFarthestCity(_remaining - distance, next + 1);
}

int Vehical::determineFarthestCity()
{
	int amount = 0;

	// then we determine if the battery level is high enough to reach the next city
	if (currentCityId == 0) amount = ChargingStation::distanceToSydney(destinationId);

	else amount = ChargingStation::distanceToCurrentCity(currentCityId, destinationId);

	// if it is we return the destination city.
	if (remainRange > amount) return destinationId;

	// If it is not, then we return the farthest station for recharge.
	int rechargeStation = calculateFarthestCity(remainRange, currentCityId);

	reset(rechargeStation);

	return rechargeStation;
}

void Vehical::displayVehicleInformation()
{
	std::cout << std::setw(5) << getVehicleID()
		<< std::setw(20) << nameMap[currentCityId]
		<< std::setw(20) << nameMap[destinationId]
		<< std::setw(20) << capacityRange
		<< std::setw(20) << remainRange
		<< std::endl;
}