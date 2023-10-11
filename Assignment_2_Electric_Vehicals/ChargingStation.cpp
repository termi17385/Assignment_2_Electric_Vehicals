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
int ChargingStation::distanceToCurrentCity(int _currentCityID, int _destinationID)
{
    if (_destinationID < _currentCityID) return 0;
    int dist = distanceMap[_destinationID];
    return (dist += distanceToCurrentCity(_currentCityID, _destinationID - 1));
}