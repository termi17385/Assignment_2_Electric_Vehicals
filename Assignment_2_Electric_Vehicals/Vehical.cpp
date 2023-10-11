#include "Vehical.h"
#include "Constants.h"
#include "ChargingStation.h"

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

int Vehical::determineFarthestCity(int _newCity, bool _recharged)
{
	// first we check if the vehicle is being recharged to determine a reset
	if (_recharged) reset(_newCity);

	int amount = 0;

	// then we determine if the battery level is high enough to reach the next city
	if (currentCityId == 0) amount = ChargingStation::distanceToSydney(destinationId);

	else amount = ChargingStation::distanceToCurrentCity(currentCityId, destinationId);

	// if it is we return the destination city.
	if (remainRange > amount) return destinationId;

	// If it is not, then we return the farthest station for recharge.
	return calculateFarthestCity(remainRange, currentCityId);
}
