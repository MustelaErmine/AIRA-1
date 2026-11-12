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

template<typename random_output_t>
random_output_t RandomStaffProvider::getValue(random_output_t min, random_output_t max) {
    std::uniform_real_distribution<random_output_t> dist(min, max);
    return dist(generator);
}

bushels_t RandomStaffProvider::getAcrCost() {
    return getValue<bushels_t>(17, 26);
}

bushels_t RandomStaffProvider::getAcrPerfomance() {
    return getValue<bushels_t>(1, 6);
}

bushels_t RandomStaffProvider::getWheetDestroyed(bushels_t old_wheet) {
    float destroyed_rate = getFloat(0, 0.07);
    
    bushels_t destroyed_wheet = static_cast<bushels_t>(std::roundf(static_cast<float>(old_wheet) * destroyed_rate));
    return destroyed_wheet;
}

bool RandomStaffProvider::getWasPlague() {
    float random_num = getFloat(0, 1);
    return random_num <= 0.15;
}