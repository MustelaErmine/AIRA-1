#include <iostream>

#include "GameDisplay.h"
#include "PlayerRoundInput.h"

void GameDisplay::showRoundStatistics(GameRoundState state) {
	setlocale(LC_ALL, "");

	std::cout << "Мой повелитель, соизволь поведать тебе," << std::endl;
	std::cout << "\tидет год " << state.years_passed << " вашего правления" << std::endl;
	if (state.humans_died > 0) {
		std::cout << "\tза год от голода умерло " << state.humans_died << " людей;" << std::endl;
	}
	if (state.humans_arrived > 0) {
		std::cout << "\tза год в город приехало " << state.humans_arrived << " людей;" << std::endl;
	}
	if (state.plague_was) {
		std::cout << "\tчума убила половину населения;" << std::endl;
	} 
	else {
		std::cout << "\tчумы не было;" << std::endl;
	}
	std::cout << "\tсейчас в городе живет " << state.population << " людей;" << std::endl;
	std::cout 
		<< "\tгород собрал " << state.wheat_added << " бушелей пшеницы, по " 
		<< state.wheat_avg << " бушелей с засеяснного акра;" << std::endl;
	std::cout << "\tкрысы уничтожили " << state.wheat_destroyed << " бушелей пшеницы;" << std::endl;
	std::cout << "\tсейчас город занимает " << state.area << " акров земли;" << std::endl;
	std::cout << "\tв этом году один акр стоит " << state.acr_cost << " бушелей пшеницы." << std::endl;
} // раунды после первого

void GameDisplay::showFirstRound(GameRoundState state) {
	setlocale(LC_ALL, "");

	std::cout << "Да здравствует повелитель! Вы только что взошли на трон, я поведаю тебе о текущих делах города:" << std::endl;
	std::cout << "\tнаселение города составляет " << state.population << " человек;" << std::endl;
	std::cout << "\tгород занимает " << state.area << " акров;" << std::endl;
	std::cout << "\tв закромах города " << state.wheat << " бушелей пшеницы;" << std::endl;
	std::cout << "\tстоимость акра земли в этом году - " << state.acr_cost << " бушелей пшеницы." << std::endl;
} // первый раунд

PlayerRoundInput GameDisplay::promptUser() {
	setlocale(LC_ALL, "");

	auto input = PlayerRoundInput();
	
	std::cout << "Что прикажете делать? ";

	std::cout << "Сколько акров земли купить? ";
	std::cin >> input.area_to_buy;

	std::cout << "Сколько акров земли продать? ";
	std::cin >> input.area_to_sell;

	std::cout << "Сколько бушелей пшеницы съесть? ";
	std::cin >> input.bushels_to_eat;

	std::cout << "Сколько акров засеять? ";
	std::cin >> input.area_to_sow;

	return input;
}

void GameDisplay::showIncorrectInput(GameRoundState state) {
	setlocale(LC_ALL, "");

	std::cout << "К великому сожалению, так не получится. "
		<< "У нас населения " << state.population << " человек, "
		<< "пшеницы " << state.wheat << " бушелей, "
		<< "и земли " << state.area << " акров." << std::endl;
}

void GameDisplay::showEndgame(result_t result) {
	setlocale(LC_ALL, "");

	switch (result) {
	case RESULT_NONE:
		std::cout << "Ошибка определения результата." << std::endl;
		break;
	case RESULT_BAD:
		std::cout << "Из-за вашей некомпетентности в"
			"управлении, народ устроил бунт, и изгнал вас их города.Теперь вы"
			"вынуждены влачить жалкое существование в изгнании" << std::endl;
		break;
	case RESULT_NORMAL:
		std::cout << "«Вы правили железной"
			"рукой, подобно Нерону и Ивану Грозному. Народ вздохнул с"
			"облегчением, и никто больше не желает видеть вас правителем" << std::endl;
		break;
	case RESULT_GOOD:
		std::cout << "Вы справились вполне неплохо, у вас, "
			"конечно, есть недоброжелатели, но многие хотели бы увидеть вас во"
			"главе города снова" << std::endl;
		break;
	case RESULT_EXCELENT:
		std::cout << "Фантастика! Карл Великий,"
			"Дизраэли и Джефферсон вместе не справились бы лучше" << std::endl;
		break;
	}
}
void GameDisplay::showLoss() {
	setlocale(LC_ALL, "");

	std::cout << "Население умирает слишком быстро, игра окончена" << std::endl;
}