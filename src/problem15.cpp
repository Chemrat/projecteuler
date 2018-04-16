#include "problem15.h"

#include <iostream>

long GetPaths(long width, long height)
{
	if (width == 0 && height == 1)
		return 1;

	long downPaths = 0;
	if (width > height)
		downPaths = height > 1 ? GetPaths(width, height - 1) : 1;

	long rightPaths = width > 1 ? GetPaths(width - 1, height) : 1;
	return downPaths + rightPaths;
}

void Problem15::Run()
{
	std::cout << GetPaths(2,2) << std::endl;
}
