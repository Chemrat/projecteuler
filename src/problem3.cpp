#include "problem3.h"

#include <iostream>

#include <set>
#include <cmath>

bool isPrime(long input)
{
	static std::set<long> primes;

	double max = std::sqrt(input);

	for (auto prime : primes)
	{
		if (input % prime == 0) return false;

		if (input > max) break;
	}

	primes.insert(input);
	return true;
}

long BruteForce(long input)
{
	for (long i = 3; i < input; i+=2)
	{
		if (!isPrime(i)) continue;

		long prime = i;
		long multiple = prime;
		long largestDivisor = 1;

		while(multiple * prime < input / 2 && input % multiple == 0)
		{
			largestDivisor = multiple;
			multiple *= prime;
		}

		if (largestDivisor != 1)
		{
			std::cout << "Division for " << prime << " : " << input / largestDivisor << "*" << largestDivisor << " = " << input << std::endl;

			input /= largestDivisor;
		}
	}

	return input;
}

void Problem3::Run()
{
	long prime = BruteForce(600851475143);

	std::cout << "Prime = " << prime << std::endl;
}
