#pragma once

#include "Vehical.h"
#include <vector>
#include <string>
#include "ChargingStation.h"
#include "Math.h"
#include <iostream>
#include <iomanip>
#include "Constants.h"

const char DELIMINATOR = ',';
const size_t LINE_SIZE = 4;

/*
	queueLength = queuePosition - 1; 
	
	if no queue then return 0.5 * 1

	avg. wait time = 0.5 x (queueLength / numberOfChargers)
*/


struct QueuedVehicle
{
	Vehical vehicle;

	// - 1 = non recharge
	int firstRechargeId = -1;
	int secondRechargeId = -1;

private:
	int cap = 0;
	int remain = 0;

public:
	void displayVehicleRecharge()
	{
		// [id dest cap remain firstR secondR]
		std::string destname = nameMap[vehicle.getDestinationID()];

		std::string first = firstRechargeId == -1 ? "----" : nameMap[firstRechargeId];
		std::string second = secondRechargeId == -1 ? "----" : nameMap[secondRechargeId];

		std::cout << std::setw(5) << vehicle.getVehicleID()
			<< std::setw(20) << destname
			<< std::setw(20) << cap
			<< std::setw(20) << remain
			<< std::setw(20) << first
			<< std::setw(20) << second << std::endl;
	}

	QueuedVehicle() = default;
	QueuedVehicle(const Vehical& vehicle)
	{
		this->vehicle = vehicle;

		firstRechargeId = -1;
		secondRechargeId = -1;

		cap = this->vehicle.getCapacityRange();
		remain = this->vehicle.getRemainingRange();
	}
};

struct StationQueues
{
	ChargingStation station;
	int queueLength = 0;

	void displayQueueInformation(bool _queued)
	{
		int numChargers = station.getNumChargers();
		int distToSyd = ChargingStation::distanceToSydney(station.getID());
		float waitingHours = Math::calculateAverageWaitTime(queueLength, numChargers);

		std::cout << std::setw(5) << station.getID()
			<< std::setw(20) << station.getName()
			<< std::setw(20) << distToSyd
			<< std::setw(20) << numChargers;
		
		if (_queued)
		{
			std::cout << std::setw(20) << queueLength;
			std::cout << std::fixed;
			if (waitingHours > 0.00) std::cout << std::setw(19) << std::setprecision(2) << waitingHours << " hours" << std::endl;
			else std::cout << std::setw(25) << "0.00 hours" << std::endl;
		}
		else std::cout << std::endl;
	}

	StationQueues() = default;

	StationQueues(const ChargingStation& station, int queueLength) : station(station), queueLength(queueLength) { }
};

class ChargingAllocation
{
private:
	StationQueues stations[NUM_CITIES];
	std::vector<QueuedVehicle> queuedVehicles; 

#pragma region Init
	int* convertLineToIntArray(std::string _line);

	void initialiseStations();
	void initialiseVehicles();

	Vehical createVehicle(int arr[]) { return Vehical(0, arr[0], arr[1], arr[2], arr[3]); }
#pragma endregion

	void outputValues(int& _destId, int& _cap, int& _remain, int& _rechargeId, int _index);

public:
	void init();
	void determineRechargeStations();
	
	Vehical getVehicle(int);
	QueuedVehicle getQueuedVehicles(int);

	ChargingStation getStation(int _cityID);
	StationQueues getStationQueue(int _cityID);
	
	// parameter for debugging
	void displayAllStationQueues(int _amt = NUM_CITIES, bool _queued = true);
	void displayAllQueuedVehicles();
};