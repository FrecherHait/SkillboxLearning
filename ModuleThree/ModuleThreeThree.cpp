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

	std::cout << "��������� ������ �������: "                          << beginHeight << "\n";
	std::cout << "������ ���������� ���������� ������� �� ���� ����: " << nightFade   << "\n";
	std::cout << "E��������� ���� �������: "                           << dailyGrowth << "\n";
	std::cout << "������ ������� � �������� �������� ���: "            << totalHeight << "\n";
}

ModuleThreeThree::~ModuleThreeThree() {

}