#pragma once

#include "GameRoundState.h"

class GameDisplay
{
public:
	void ShowRoundStatistics(GameRoundState state); // раунды после первого
	void ShowFirstRound(GameRoundState state); // первый раунд
};

