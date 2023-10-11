#pragma once

#include <string>
#include "Constants.h"

class ChargingStation
{
public:

	ChargingStation(int _cityId)
	{
		cityId = _cityId;
		cityName = nameMap[_cityId];
		distanceToLastCity = distanceMap[_cityId];
		numberOfChargers = chargersMap[_cityId];
	}
	
	int getID() { return cityId; }
	std::string getName() { return cityName; }
	int getDistanceToLastCity() { return distanceToLastCity; }
	int getNumChargers() { return numberOfChargers; }

	static int distanceToSydney(int _cityId);
	static int distanceToCurrentCity(int _currentCityID, int _destinationID);

	void diplayInformation();

private:
	
	int cityId;
	std::string cityName;
	int distanceToLastCity;
	int numberOfChargers;
};