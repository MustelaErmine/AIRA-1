#include "GameLoop.h"
#include "GameRoundState.h"
#include "GameDisplay.h"
#include "GameResult.h"
#include "RoundStateReadWriter.h"
#include "RandomStaffProvider.h"

void GameLoop::mainLoop() {
	makeProvider();

	// check the file to start and make 
	GameRoundState state = GameRoundState();

	bool save_exists = RoundStateReadWriter::fileExists(save_file_path);

	RoundStateReadWriter readWriter = RoundStateReadWriter(save_file_path);

	if (save_exists) {
		state = readWriter.read();

		if (state.years_passed >= 10) {
			state = GameRoundState::MakeDefault();
		}
	}
	else {
		state = GameRoundState::MakeDefault();
	}

	// main loop
	readWriter.write(state);

	while (state.years_passed < 10) {
		// show stats
		if (state.years_passed == 0) {
			GameDisplay::showFirstRound(state);
		}
		else {
			GameDisplay::showRoundStatistics(state);
		}
		
		// get user input
		auto input = GameDisplay::promptUser();
		while (!state.canPerform(input)) {
			GameDisplay::showIncorrectInput(state);
			input = GameDisplay::promptUser();
		}

		// perform the round
		auto result = PerformRound(state, input);

		// check the imediate loss
		if (result.loss_imediatly) {
			GameDisplay::showLoss();
			return;
		}

		state = result.new_state;

		// write state and continue
		readWriter.write(state);
	}

	auto result = determineResult(state);
	GameDisplay::showEndgame(result);
}