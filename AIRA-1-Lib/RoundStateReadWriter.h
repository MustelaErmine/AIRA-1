#pragma once

#include <fstream>
#include <string>

#include "GameRoundState.h"

class RoundStateReadWriter
{
public:
	explicit RoundStateReadWriter(const std::string& path);

	void write(GameRoundState state);
	GameRoundState read();

	static bool fileExists(const std::string& path);
private:
	std::fstream stream;
};

