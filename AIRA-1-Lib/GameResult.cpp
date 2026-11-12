#include "GameResult.h"
#include "GameConfig.h"


result_t determineResult(GameRoundState roundState) {
	float rounds = GameConfig::number_of_rounds;
	
	float P = static_cast<float>(roundState.total_number_of_died) / rounds;
	float L = static_cast<float>(roundState.area) / static_cast<float>(roundState.population);

	if (P > 0.33 && L < 7) {
		return RESULT_BAD;
	}
	else if (P > 0.10 && L < 9) {
		return RESULT_NORMAL;
	}
	else if (P > 0.03 && L < 10) {
		return RESULT_GOOD;
	}
	else {
		return RESULT_EXCELENT;
	}
}