#pragma once
class Vehical
{
private:

	void reset(int);

	int currentCityId = 0;	//initialised with 0 for Sydney
	int vehicleId;			//can be any integer
	int destinationId;		//any city other than Sydney
	int capacityRange;		//in kilometers
	int remainRange;		//in kilometers

public:

	int calculateFarthestCity(int _remaining, int _currentCity);
	int determineFarthestCity();
	
	void setDestinationID(int _newDestination) { destinationId = _newDestination; }
	
	Vehical(int currentCityId, int vehicleId, int destinationId, int capacityRange, int remainRange)
		: currentCityId(currentCityId), vehicleId(vehicleId), destinationId(destinationId), capacityRange(capacityRange), remainRange(remainRange) {}
};