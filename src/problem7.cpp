#include "problem7.h"
#include "util.h"

#include <iostream>

void Problem7::Run()
{
	int index = 2;
	int candidate = 1;
	while (index <= 10001)
	{
		candidate+=2;

		if (isPrime(candidate))
		{
			std::cout << candidate << " is prime #" << index << std::endl;
			index++;
		}

	}

	std::cout << "Prime: " << candidate << std::endl;
}
