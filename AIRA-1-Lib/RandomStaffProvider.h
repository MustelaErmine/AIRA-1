#pragma once

#include <random>

#include "GameTypes.h"

class RandomStaffProvider
{
public:
	RandomStaffProvider() = default;
    RandomStaffProvider(int seed) : generator(seed) {}
	
    bushels_t getAcrCost();
    bushels_t getAcrPerfomance();
    bushels_t getWheetDestroyed(bushels_t old_wheet);
    bool getWasPlague();

private:
	std::mt19937 generator{ std::random_device{}() };

    int getInt(int min, int max);

    float getFloat(float min, float max);

    template<typename TOutput>
    TOutput getValue(TOutput min, TOutput max);
};

RandomStaffProvider getProvider();
void makeProvider();