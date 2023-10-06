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

	static int distanceToSydney(int _cityId);
	
	void diplayInformation();

	int getCityId();
	
	std::string getCityName();

	int getDistanceToLastCity();
	
	int getNumberOfChargers();

private:
	
	int cityId;
	std::string cityName;
	int distanceToLastCity;
	int numberOfChargers;
};