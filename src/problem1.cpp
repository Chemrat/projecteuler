#include "problem1.h"

#include <iostream>

#include "util.h"

void Problem1::Run()
{
	// Sample
	int sum = arithmeticProgression(3, 10);
	sum += arithmeticProgression(5, 10);

	std::cout << "Total: " << sum << std::endl;

	// Problem
	sum = arithmeticProgression(3, 1000);
	sum += arithmeticProgression(5, 1000);
	sum -= arithmeticProgression(3*5, 1000); // to remove duplicates from the sums
	std::cout << "Total: " << sum << std::endl;
}
