#include "util.h"

#include <set>
#include <cmath>

bool isPrime(long input)
{
	static std::set<long> primes;

	double max = std::sqrt(input);

	for (auto prime : primes)
	{
		if (input % prime == 0) return false;

		if (prime > max) break;
	}

	primes.insert(input);
	return true;
}

