#pragma once
typedef float population_t;
typedef float area_t;
typedef float bushels_t;

class GameState
{
	population_t population;
	area_t area;
	bushels_t wheat;

	int years_passed;
};

