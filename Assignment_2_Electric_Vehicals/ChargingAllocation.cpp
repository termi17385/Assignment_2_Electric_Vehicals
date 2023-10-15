#include "ChargingAllocation.h"
#include "Constants.h"
#include "DemandGenerator.h"
#include <fstream>
#include <iostream>
#include <iomanip>

#pragma region Initialisation
int* ChargingAllocation::convertLineToIntArray(std::string _line)
{
	int* tokens = new int[LINE_SIZE]{};

	std::string temp = _line;

	for (int i = 0; i < LINE_SIZE; i++)
	{
		/*
				 0    1    2
			[xxxx,xxxx,xxxx,xxxx]
		*/

		int position = temp.find(DELIMINATOR);
		tokens[i] = std::stoi(temp.substr(0, position));
		if(i < 3) temp.erase(0, position + 1);
	}

	return tokens;
}

void ChargingAllocation::initialiseStations()
{
	for (int i = 0; i < NUM_CITIES; i++)
	stations[i] = StationQueues(ChargingStation(i), 0);
}

void ChargingAllocation::initialiseVehicles()
{
	std::ifstream readFile(DEMANDS_PATH);
	if (readFile.is_open())
	{
		std::string next;
		int* demandsArr = new int[LINE_SIZE];

		while(std::getline(readFile, next))
		{
			size_t size = next.size();

			if (size <= 0) continue;

			next = next.substr(1, size - 2);

			demandsArr = convertLineToIntArray(next);

			QueuedVehicle newVehicle(createVehicle(demandsArr));

			queuedVehicles.push_back(newVehicle);

			delete[] demandsArr;
		}
	}
	else std::cout << "ERROR READING CHARGING DEMANDS";
}

void ChargingAllocation::outputValues(int& _destId, int& _cap, int& _remain, int& _rechargeId, int _index)
{
	Vehical* v = &queuedVehicles[_index].vehicle;

	_destId = v->getDestinationID();

	_cap = v->getCapacityRange();

	_remain = v->getRemainingRange();

	_rechargeId = v->determineFarthestCity();
}

void ChargingAllocation::determineRechargeStations()
{
	// if the vehicle does not need to recharge remove the vehicle
	
	int count = 0;
	size_t size = queuedVehicles.size();
	int destId = 0, cap = 0, remain = 0, rechargeId = 0;

	for (int i = 0; i < size; i++)
	{
		QueuedVehicle* q = &queuedVehicles[i];

		outputValues(destId, cap, remain, rechargeId, i);

		if (rechargeId == destId) continue;
		
		// Remove non pending vehicle ?
		//pendingVehicles.erase(pendingVehicles.begin() + i);
		//i--;
		
		// if a vehicle needs to recharge, send it to the queue of the station to recharge at
		q->firstRechargeId = rechargeId;

		stations[rechargeId].queueLength++;

		outputValues(destId, cap, remain, rechargeId, i);

		if (rechargeId == destId) continue;

		q->secondRechargeId = rechargeId;
		
		stations[rechargeId].queueLength++;
	}

	// todo: Change this later to be more accurate
	std::cout << count << "/" << size << " vehicles made it to their destinations" << std::endl;
}

void ChargingAllocation::init()
{
	initialiseStations();
	initialiseVehicles();
}
#pragma endregion

// used purely for debugging.
Vehical ChargingAllocation::getVehicle(int _id) {  return getQueuedVehicles(_id).vehicle; }
QueuedVehicle ChargingAllocation::getQueuedVehicles(int _id) { return queuedVehicles[_id]; }
ChargingStation ChargingAllocation::getStation(int _cityID) { return getStationQueue(_cityID).station; }
StationQueues ChargingAllocation::getStationQueue(int _cityID) { return stations[_cityID]; }

void ChargingAllocation::displayAllStationQueues(int _amt, bool _queued)
{
	std::cout << std::setw(5) << "Location Id"
		<< std::setw(20) << "Location name"
		<< std::setw(20) << "Distance to Sydney"
		<< std::setw(20) << "no of Chargers";

	if (_queued)
	{
		std::cout << std::setw(20) << "Queue length"
			<< std::setw(20) << "Waiting hours";
	}
	
	std::cout << std::endl;
	

	if (_amt > NUM_CITIES) _amt = NUM_CITIES;
	for (int i = 0; i < _amt; i++)
		getStationQueue(i).displayQueueInformation(_queued);
}

void ChargingAllocation::displayAllQueuedVehicles()
{
	std::cout << std::setw(5) << "Vehicle Id"
		<< std::setw(20) << "Destination"
		<< std::setw(20) << "Capacity Range"
		<< std::setw(20) << "Remaining Range"
		<< std::setw(20) << "First recharge"
		<< std::setw(20) << "Second recharge"
		<< std::endl;

	size_t size = queuedVehicles.size();
	for (int i = 0; i < size; i++) 
	queuedVehicles[i].displayVehicleRecharge();
}

/*std::cout << "Vehicle Id" << std::setw(20) << "Destination Id" << std::setw(20)
<< "Capacity Range" << std::setw(20) << "Remaining Range" << std::endl;*/