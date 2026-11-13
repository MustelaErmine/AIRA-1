#include <math.h>

#include "RandomStaffProvider.h"

int RandomStaffProvider::getInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(generator);
}

float RandomStaffProvider::getFloat(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(generator);
}

template<typename TOutput>
TOutput RandomStaffProvider::getValue(TOutput min, TOutput max) {
    std::uniform_real_distribution<TOutput> dist(min, max);
    return dist(generator);
}

template<>
bushels_t RandomStaffProvider::getValue(bushels_t min, bushels_t max) {
    std::uniform_int_distribution<bushels_t> dist(min, max);
    return dist(generator);
}

bushels_t RandomStaffProvider::getAcrCost() {
    return getValue<bushels_t>(17, 26);
}

bushels_t RandomStaffProvider::getAcrPerfomance() {
    return getValue<bushels_t>(1, 6);
}

bushels_t RandomStaffProvider::getWheetDestroyed(bushels_t old_wheet) {
    float destroyed_rate = getFloat(0, 0.07f);
    
    bushels_t destroyed_wheet = static_cast<bushels_t>(std::roundf(static_cast<float>(old_wheet) * destroyed_rate));
    return destroyed_wheet;
}

bool RandomStaffProvider::getWasPlague() {
    float random_num = getFloat(0, 1);
    return random_num <= 0.15;
}

RandomStaffProvider provider;

void makeProvider() {
    provider = RandomStaffProvider();
}

RandomStaffProvider getProvider() {
    return provider;
}