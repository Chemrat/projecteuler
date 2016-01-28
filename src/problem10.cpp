#include "problem10.h"
#include "util.h"

#include <iostream>

void Problem10::Run()
{
	long sum = 2;
	for (long i = 3; i < 2000000; i+=2)
	{
		if (isPrime(i))
			sum += i;
	}

	std::cout << sum << std::endl;
}
