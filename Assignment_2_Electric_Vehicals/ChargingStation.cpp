#include "ChargingStation.h"
#include <iostream>
#include <iomanip>

void ChargingStation::diplayInformation()
{
    std::cout << std::setw(20) << cityId;
    std::cout << std::setw(20) << cityName;
    std::cout << std::setw(20) << distanceToLastCity;
    std::cout << std::setw(20) << numberOfChargers << "\n";
}

int ChargingStation::distanceToSydney(int _cityId)
{
    if (_cityId <= 0) return 0;
    int dist = distanceMap[_cityId];
    return (dist += distanceToSydney(_cityId - 1));
}

#pragma region Getters
int ChargingStation::getCityId()
{
    return cityId;
}

std::string ChargingStation::getCityName()
{
    return cityName;
}

int ChargingStation::getDistanceToLastCity()
{
    return distanceToLastCity;
}

int ChargingStation::getNumberOfChargers()
{
    return numberOfChargers;
}
#pragma endregion

