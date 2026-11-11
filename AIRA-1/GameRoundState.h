#pragma once
typedef int population_t;
typedef int area_t;
typedef int bushels_t;

class GameRoundState
{
public:
	population_t population;
	area_t area;
	bushels_t wheat;

	int years_passed;

	population_t humans_died;
	population_t humans_arrived;
	bool plague_was;
	

	GameRoundState MakeDefault();
};

