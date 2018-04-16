#include "dragon_vs_knight.h"

#include <iostream>
#include <list>
#include <map>
#include <thread>
#include <cmath>
#include <chrono>
#include <mutex>

void roll(const std::map<int, double> &dice,
		  std::map<int, double> &sumDistribution,
		  int sum,
		  double chance,
		  int depth)
{
	if (depth == 0) {
		// Lowest level of the tree reached
		if (sumDistribution.find(sum) == sumDistribution.end())
			sumDistribution[sum] = chance;
		else
			sumDistribution[sum] += chance;
		return;
	}

	// Traverse all paths to the next tree level from here
	for (const auto &pair : dice) {
		roll(dice, sumDistribution, sum + pair.first, chance * pair.second, depth - 1);
	}
}

void runChecks(const std::map<int, double> &dice,
			   int rolls,
			   int enemyHP,
			   std::string enemyName,
			   std::mutex &cout_lock)
{
	std::map<int, double> sumDistribution;

	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	roll(dice, sumDistribution, 0, 1, rolls);
	std::chrono::high_resolution_clock::time_point finish = std::chrono::high_resolution_clock::now();

	double chanceOfKill = 0;
	double chanceSum = 0;
	double good_outcomes = 0;
	for (const auto &sum : sumDistribution)
	{
		//std::cout << "Sum: " << sum.first << " with probability: " << sum.second << std::endl;
		chanceSum += sum.second;

		if (sum.first >= enemyHP)
		{
			good_outcomes++;
			chanceOfKill += sum.second;
		}
	}

	// Some error accumulates due to limited nature of floats
	// std::cout << "Sanity check: " << chanceSum << " " << 1. - chanceSum << std::endl;
	// if (chanceSum != 1.)
	//	abort();

	std::lock_guard<std::mutex> guard(cout_lock);
	std::cout << "Hits: " << rolls << " | Chance to kill " << enemyName << " is " << chanceOfKill
			  << " (" << good_outcomes << " outcomes out of " << sumDistribution.size() << ") "
			  << "[ Combinations: " << std::pow(dice.size(), rolls) << " ]"
			  << "{ Time: " << std::chrono::duration_cast<std::chrono::seconds>( finish - start ).count() << " s }" << std::endl;
}

void DragonVsKnight::Run()
{
	// used for initial testing
	std::map<int, double> dice = { {1, 1./6},
								   {2, 1./6},
								   {3, 1./6},
								   {4, 1./6},
								   {5, 1./6},
								   {6, 1./6},
								 };

	/*
	 * Knight's effective damage: 80 - 60 = 20
	 * Knight's crit damage: 20 * 30 = 60
	 */

	std::map<int, double> knightHits = { {20, 2./3},
										 {180, 1./3},
									   };

	/*
	 * Dragon's effective damage: 120 - 30 = 90
	 * Dragon's chance to hit with normal damage: (3/4) * (1/10) = 3/40
	 * Dragon's chance to insta-kill: (1/4) * (1/10) = 1/40
	 * Should be safe to assume insta-kill damage as 300
	 */
	std::map<int, double> dragonHits = { {90, 3./40},
										 {300, 1./40},
										 {0, 9./10},
									   };

	/*
	 * In general, this is a sub-optimal algorithm, due to combinatory nature of the problem
	 * Calculating hit 24 for dragon takes ~3 hours on 3 GHz ivy bridge
	 * Probability distribution for N is not reused for N+1, should be possible to fix but I'm too lazy to figure it out
	 */
	std::mutex cout_lock;
	std::thread dragon([&](){
		for (int rolls = 1; rolls<100; rolls++)
		{
			runChecks(knightHits, rolls, 1500, "dragon", cout_lock);
		}
	});

	std::thread knight([&](){
		for (int rolls = 1; rolls<100; rolls++)
		{
			runChecks(dragonHits, rolls, 300, "knight", cout_lock);
		}
	});

	dragon.join();
	knight.join();
}
