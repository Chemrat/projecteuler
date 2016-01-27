#include "problem6.h"

#include <iostream>

long squaresDiff(int length)
{
	long result = 0;

	for (int i = 1; i < length; i++)
		for (int j = i + 1; j <= length; j++)
		{
			result += 2*i*j;
		}

	return result;
}

void Problem6::Run()
{
	std::cout << "Result for 10 = " << squaresDiff(10) << std::endl;
	std::cout << "Result for 100 = " << squaresDiff(100) << std::endl;
}
