#include<vector>
#include<iostream>
#include"ChargingStation.h"
#include<iomanip>
#include<unordered_map>

using namespace std;

#pragma region Stations Declarations
std::vector<ChargingStation> stations;
void initialiseStations();
void displayAllStations();
#pragma endregion

int calculateFarthestCity(int _destination, int _remaining)
{
	int next = 0; // start at syd
	int capacity = _remaining; // remainingCapactiy
	bool outOfFuel = false;

	int count = 0;

	int ans = 0;

	cout << ans << endl;

	if (capacity >= ans) return _destination;

	do
	{
		count++;
		int distance = distanceMap[next + 1];

		if (capacity >= distance)
		{
			next++;
			
			capacity -= distance;

			cout << "Remaining Distance: " + distance << endl;
		}

		else
		{
			outOfFuel = true;
			continue;
		}

	} while (!outOfFuel || count < NUM_CITIES);

	return next;
}

int calculateFarthestCity(int _remaining, int _index)
{
	if (_remaining >= ChargingStation::distanceToSydney(2))
		return 2;

	int next = _index;

	int distance = distanceMap[next + 1];

	if (_remaining < distance) return next;

	return testFunction(_remaining - distance, next + 1);
}

int main()
{
	cout << calculateFarthestCity(90, 0);
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