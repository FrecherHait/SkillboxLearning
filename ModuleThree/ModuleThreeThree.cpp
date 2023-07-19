#include "ModuleThreeThree.h"

ModuleThreeThree::ModuleThreeThree() {
	beginHeight = 0;
	dailyGrowth = 0;
	nightFade   = 0;
	totalHeight = 0;
}

void ModuleThreeThree::run() {
	beginHeight = 100;
	dailyGrowth = 50;
	nightFade   = 20;
	totalHeight = beginHeight + (dailyGrowth - nightFade) * 2 + dailyGrowth / 2;

	std::cout << "Начальная высота бамбука: "                          << beginHeight << "\n";
	std::cout << "Размер съедаемого гусеницами бамбука за одну ночь: " << nightFade   << "\n";
	std::cout << "Eжедневный рост бамбука: "                           << dailyGrowth << "\n";
	std::cout << "Высота бамбука к середине третьего дня: "            << totalHeight << "\n";
}

ModuleThreeThree::~ModuleThreeThree() {

}