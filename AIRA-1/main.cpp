#include <string>
#include <iostream>
#include <windows.h>

#include "../AIRA-1-Lib/GameLoop.h"

int main() {
	setlocale(LC_ALL, "");

	std::string save_path = ".\\save.txt";

	auto game = GameLoop();
	game.save_file_path = save_path;
	game.mainLoop();

	return 0;
}