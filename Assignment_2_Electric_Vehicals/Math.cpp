#include "Math.h"
#include <stdlib.h>


/// <summary>
/// Will return a rand value between a and b
/// </summary>
/// <param name="a">starting value</param>
/// <param name="b">the range</param>
int Math::randomRange(int a, int b)
{
	int range = b - a;
	return a + (rand() % range);
}
