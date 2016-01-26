#include "problem4.h"

#include <iostream>

bool isPolyndrome(long input)
{
	long rightSide = 0;
	long number = 0;

	while (rightSide < input)
	{
		number = input % 10;
		input /= 10;

		rightSide *= 10;
		rightSide += number;

		if (rightSide == input || rightSide * 10 == input)
			return true;
	}

	return false;
}

void Problem4::Run()
{
	long result = 0;
	for (long a = 999; a > 1; a--)
		for (long b = 999; b > 1; b--)
			if (isPolyndrome(a*b))
			{
				std::cout << a << "*" << b << "=" << a*b << std::endl;
				if (a*b > result)
					result = a * b;
			}

	std::cout << result << std::endl;
}
