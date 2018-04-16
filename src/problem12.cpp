#include "problem12.h"
#include "util.h"

#include <iostream>

#include <vector>
#include <deque>
#include <cmath>

int numberOfDivisors(std::vector<int> exponents)
{
	int divisors = 1;
	for (auto exponent : exponents)
		divisors *= (exponent + 1);
	return divisors;
}

// The joke's on me, initially I was using arithmeticProgression from util

int numberOfDivisors2(long input)
{
	int result = 2;
	for (int divisor = 2; divisor < input; divisor++)
		if (input % divisor == 0)
			result++;
	return result;
}

bool isTriangularNumber(long long input)
{
	double root  = std::sqrt(8*input + 1);
	long rootL = root;
	return (rootL == root && rootL % 2 == 1);
}

void Problem12::Run()
{
	std::deque<int> primes;
	primes.push_back(2);
	int currentExp = 1;
	for (int i = 3; i < 1000; i+=2)
		if (isPrime(i))
			primes.push_back(i);

	long candidate = 0;
	do {
		std::cout << "Checking " << std::pow(primes.at(0), currentExp) << " against " << primes.at(9) << std::endl;
		if (std::pow(primes.at(0), currentExp) > primes.at(9))
		{
			currentExp = 1;
			primes.pop_front();
		}

		candidate = std::pow(primes.at(0), currentExp);

		for (int i = 1; i < 9; i++)
			candidate *= primes.at(i);

		currentExp++;

		std::cout << "Trying " << candidate << std::endl;

	} while (!isTriangularNumber(candidate));

	std::cout << candidate << std::endl;

	//std::cout << isTriangularNumber(2*3*5*7*11*13*17*19*23) << std::endl;
//	std::cout << numberOfDivisors2(2*3*5*7*11*13*17*19*23)<< std::endl;

//	std::vector<int> exp = {1,1,1,1,1,1,1,1,1};
//	std::cout << numberOfDivisors(exp);

	return;
}
