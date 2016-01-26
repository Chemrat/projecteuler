#include "problem2.h"

#include <iostream>

long BruteForce()
{
	// Looks pretty dumb, but seems to be fast enough (under 1ms on Core i5)
	long a = 1;
	long b = 2;
	long sum = 0;

	while (b < 4000000)
	{
		if (b % 2 == 0)
			sum += b;

		long tmp = b;
		b += a;
		a = tmp;
	}

	return sum;
}

void Problem2::Run()
{
	std::cout << "Sum = " << BruteForce() << std::endl;
}
