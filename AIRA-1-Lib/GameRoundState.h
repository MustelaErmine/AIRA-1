#pragma once

#include "PlayerRoundInput.h"
#include "GameTypes.h"

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
	bushels_t wheat_got;
	bushels_t wheat_avg;
	bushels_t wheat_added;
	bushels_t wheat_destroyed;
	bushels_t acr_cost;

	population_t total_number_of_died;

	static GameRoundState MakeDefault();

	bool canPerform(PlayerRoundInput input);
};

class RoundPerformResult {
public:
	GameRoundState new_state;
	bool loss_imediatly;
};

RoundPerformResult PerformRound(GameRoundState previous, PlayerRoundInput input);
