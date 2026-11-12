#pragma once

#include "GameRoundState.h"
#include "PlayerRoundInput.h"
#include "GameResult.h"

class GameDisplay
{
public:
	static void showRoundStatistics(GameRoundState state); // раунды после первого
	static void showFirstRound(GameRoundState state); // первый раунд

	static PlayerRoundInput promptUser();

	static void showEndgame(result_t result);
	static void showLoss();
};

