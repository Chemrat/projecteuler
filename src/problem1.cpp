#include "problem1.h"

#include <iostream>

int Sum(int base, int limit)
{
	int max = limit - 1;
	while (max % base != 0)
		max--;
	int n = max / base;
	int sum = n * (base + max) / 2;
	return sum;
}

void Problem1::Run()
{
	// Sample
	int sum = Sum(3, 10);
	sum += Sum(5, 10);

	std::cout << "Total: " << sum << std::endl;

	// Problem
	sum = Sum(3, 1000);
	sum += Sum(5, 1000);
	sum -= Sum(3*5, 1000); // to remove duplicates from the sums
	std::cout << "Total: " << sum << std::endl;
}
