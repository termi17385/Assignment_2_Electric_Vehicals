#include "Math.h"
#include <stdlib.h>


/// <summary>
/// Will return a rand value between a and b
/// </summary>
/// <param name="a">starting value</param>
/// <param name="b">the range</param>
int Math::randomRange(int a, int b)
{
	if (a == b) return a;

	int range = b - a;

	return a + (rand() % range);
}

/// <param name="a">queuePosition - 1</param>
/// <param name="b">no. of chargers</param>
/// <returns></returns>
float Math::calculateAverageWaitTime(int a, int b)
{
	if (a == 0) return 0.00f;
	else return 0.5f * ((float)a / (float)b);
}

