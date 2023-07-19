#include <iostream>
#include "ModuleThreeOne.h"
#include "ModuleThreeTwo.h"
#include "ModuleThreeThree.h"
#include "ModuleThreeFour.h"

int main() {
	setlocale(LC_ALL, "rus");          // Для вывода русских символов в консоль Visual Studio
	
	ModuleThreeOne moduleThreeOne;     // Класс первого задания
	ModuleThreeTwo moduleThreeTwo;     // Класс второго задания
	ModuleThreeThree moduleThreeThree; // Класс третьего задания
	ModuleThreeFour moduleThreeFour;   // Класс третьего задания

	std::cout << "----Практическое задание для модуля 3 \"Ввод данных пользователя.Строки\"----\n";
	
	while (true) {
		int cmdNum; // Переменная для ввода номера команд
		std::cout << "\n";
		std::cout << "1 - Задание 1 \"Симулятор маршрутки\""       << "\n";
		std::cout << "2 - Задание 2 \"Обмен местами\""             << "\n";
		std::cout << "3 - Задание 3 \"Злостные вредители\""        << "\n";
		std::cout << "4 - Задание 4 \"Повышаем градус сложности\"" << "\n";
		std::cout << "0 - Выход"                                   << "\n";
		std::cout << "Введите номер команды: ";
		std::cin  >> cmdNum;

		switch (cmdNum) {
		case 0:
			return 0;
		case 1:
			moduleThreeOne.run();
			break;
		case 2:
			moduleThreeTwo.run();
			break;
		case 3:
			moduleThreeThree.run();
			break;
		case 4:
			moduleThreeFour.run();
			break;
		}
	}
}