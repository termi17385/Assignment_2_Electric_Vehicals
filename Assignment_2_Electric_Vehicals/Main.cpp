#include"ChargingStation.h"
#include<iostream>
#include<iomanip>
#include<vector>
#include "Vehical.h"
#include "DemandGenerator.h"

using namespace std;

#pragma region Stations Declarations
std::vector<ChargingStation> stations;
void initialiseStations();
void displayAllStations();
#pragma endregion



int main()
{
	DemandGenerator dg;
	dg.writeDemands(MAX_DEMANDS);
}	

#pragma region Station Definitions
void initialiseStations()
{
	for (int i = 0; i < NUM_CITIES; i++)
	{
		stations.push_back(ChargingStation(i));
	}
}

void displayAllStations()
{
	std::cout << setw(22) << "City ID";
	std::cout << setw(20) << "City Name";
	std::cout << setw(25) << "Dist. to City(km)";
	std::cout << setw(20) << "no. of chargers" << endl << endl;

	for (int i = 0; i < NUM_CITIES; i++)
	{
		stations[i].diplayInformation();
	}
}
#pragma endregion