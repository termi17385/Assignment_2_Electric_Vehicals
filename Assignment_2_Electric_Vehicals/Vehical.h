#pragma once
class Vehical
{
private:

	void reset(int);

	int currentCityId	= 0;	//initialised with 0 for Sydney
	int vehicleId		= 0;	//can be any integer
	int destinationId	= 0; 	//any city other than Sydney
	int capacityRange	= 0;	//in kilometers
	int remainRange		= 0;	//in kilometers

public:

	int getCurrentCityID()	{ return currentCityId; }
	int getVehicleID()		{ return vehicleId;		}
	int getDestinationID()	{ return destinationId; }
	int getCapacityRange()	{ return capacityRange; }
	int getRemainingRange() { return remainRange;	}

	int calculateFarthestCity(int _remaining, int _currentCity);
	int determineFarthestCity();
	
	void setDestinationID(int _newDestination) { destinationId = _newDestination; }
	void displayVehicleInformation();

	Vehical(int currentCityId, int vehicleId, int destinationId, int capacityRange, int remainRange)
		: currentCityId(currentCityId), vehicleId(vehicleId), destinationId(destinationId), capacityRange(capacityRange), remainRange(remainRange) {}

	Vehical() = default;
};