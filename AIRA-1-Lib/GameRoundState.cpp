#include "GameRoundState.h"
#include "RandomStaffProvider.h"

GameRoundState GameRoundState::MakeDefault() {
	auto provider = getProvider();

	auto state = GameRoundState();

	state.population = 100;
	state.wheat = 2800;
	state.area = 1000;

	state.humans_died = 0;
	state.humans_arrived = 0;
	state.plague_was = false;
	state.wheat_got = 0;
	state.wheat_avg = 0;
	state.wheat_destroyed = 0;
	state.acr_cost = provider.getAcrCost();

	state.total_number_of_died = 0;

	return state;
}

RoundPerformResult PerformRound(GameRoundState previous, PlayerRoundInput input) {
	auto provider = getProvider();

	RoundPerformResult loss_imediatly_result = RoundPerformResult();
	loss_imediatly_result.new_state = previous;
	loss_imediatly_result.loss_imediatly = true;
	
	GameRoundState state = previous;

	// area being bought and sold
	state.area += input.area_to_buy;
	state.area -= input.area_to_sell;

	// wheat being sowed
	state.wheat_avg = provider.getAcrPerfomance();
	state.wheat += state.wheat_avg * input.area_to_sow;

	// wheat being destroyed
	state.wheat_destroyed = provider.getWheetDestroyed(state.wheat);
	state.wheat -= state.wheat_destroyed;

	// wheat being eaten and people die
	state.humans_died = state.population - (input.bushels_to_eat / 20);
	state.population -= state.humans_died;
	state.total_number_of_died += state.humans_died;

	// loss if die > 45%
	float died_percent = 
		static_cast<float>(state.humans_died) 
		/ static_cast<float>(state.population);
	if (died_percent > 0.45) {
		return loss_imediatly_result;
	}

	// humans arrive
	state.humans_arrived = state.humans_died / 2 + (5 - state.wheat_avg) * state.wheat / 600 + 1;
	if (state.humans_arrived < 0) {
		state.humans_arrived = 0;
	}
	if (state.humans_arrived > 50) {
		state.humans_arrived = 50;
	}
	state.population += state.humans_arrived;

	// plague being
	state.plague_was = provider.getWasPlague();

	// new area cost
	state.acr_cost = provider.getAcrCost();

	auto result = RoundPerformResult();
	result.new_state = state;
	result.loss_imediatly = false;
	return result;
}

bool GameRoundState::canPerform(PlayerRoundInput input) {
	bool correct_input =
		input.area_to_buy >= 0
		&& input.area_to_sell >= 0
		&& input.area_to_sow >= 0
		&& input.bushels_to_eat >= 0;
	
	area_t new_area = area + input.area_to_buy - input.area_to_sell;
	bool can_sow_area = new_area <= input.area_to_sow;
	bool can_sow_people = input.area_to_sow <= population * 10;

	bushels_t buy_cost = input.area_to_buy * acr_cost;
	bool can_buy = buy_cost <= wheat;

	bushels_t wheat_remain = wheat - buy_cost;
	bool can_sow_wheat = wheat_remain >= input.area_to_sow / 2;

	return correct_input
		&& can_sow_area
		&& can_sow_people
		&& can_buy
		&& can_sow_wheat;
}