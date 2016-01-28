#include "problem9.h"

#include <iostream>

bool isPythagoreanTriplet(int a, int b, int c)
{
	return a*a + b*b == c*c;
}

void Problem9::Run()
{
	for (int c = 3; c < 500; c++)
		for (int b = ((1000 - c) / 2); b < c; b++)
		{
			int a = 1000 - b - c;
			if (isPythagoreanTriplet(a,b,c))
			{
				std::cout << a * b * c << std::endl;
				return;
			}
		}
}
