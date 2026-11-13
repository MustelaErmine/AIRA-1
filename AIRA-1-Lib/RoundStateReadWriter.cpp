#include <string>
#include <filesystem>
#include <iostream>
#include <cstring>

#include "RoundStateReadWriter.h"

RoundStateReadWriter::RoundStateReadWriter(const std::string& path) : stream(path, std::ios::out | std::ios::in) {
	if (!stream.is_open()) {
		std::ofstream ofstream = std::ofstream(path);
		if (!ofstream.is_open()) {
			ofstream.close();
			throw std::runtime_error("");
		}
		ofstream.close();
		stream.open(path, std::ios::out | std::ios::in);
		return;
	}
}

void RoundStateReadWriter::write(GameRoundState state) {

	stream.seekp(std::ios::beg);

	stream << state.population << " ";
	stream << state.area << " ";
	stream << state.wheat << " ";
	stream << state.years_passed << " ";
	stream << state.humans_died << " ";
	stream << state.humans_arrived << " ";
	stream << state.plague_was << " ";
	stream << state.wheat_got << " ";
	stream << state.wheat_avg << " ";
	stream << state.wheat_added << " ";
	stream << state.wheat_destroyed << " ";
	stream << state.acr_cost << " ";
	stream << state.total_number_of_died << " ";
	stream.flush();
}

GameRoundState RoundStateReadWriter::read() {
	stream.seekg(std::ios::beg);

	GameRoundState state = GameRoundState();

	stream >> state.population;
	stream >> state.area;
	stream >> state.wheat;
	stream >> state.years_passed;
	stream >> state.humans_died;
	stream >> state.humans_arrived;
	stream >> state.plague_was;
	stream >> state.wheat_got;
	stream >> state.wheat_avg;
	stream >> state.wheat_added;
	stream >> state.wheat_destroyed;
	stream >> state.acr_cost;
	stream >> state.total_number_of_died;

	return state;
}

bool RoundStateReadWriter::fileExists(const std::string& path) {
	return std::filesystem::exists(path);
}