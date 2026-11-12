#pragma once

#include "GameRoundState.h"

typedef enum{ RESULT_NONE, RESULT_BAD, RESULT_NORMAL, RESULT_GOOD, RESULT_EXCELENT} result_t;

result_t determineResult(GameRoundState roundState);