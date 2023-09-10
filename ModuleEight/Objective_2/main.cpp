#include <iostream>
#include <format>
#include <cmath>

int main() {

	// Для вывода русских символов в консоль Visual Studio
	setlocale(LC_ALL, "ru_RU.utf8");          

	std::cout << "----Практическое задание для модуля 8 \"Числа с плавающей запятой. Математические вычисления\"----" << "\n";
	std::cout << "---------------------Задание 2 \"Immolate Improved!\"---------------------" << "\n";

	auto checkValue = [&](float val) {
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cout << "Ошибка! Вы ввели не число." << "\n";
			exit(-1);
		}
		else if (val <= 0) {
			std::cout << "Ошибка! Вы ввели отрицательное число или 0.";
			exit(-2);
		}
		else if (val > 1.0) {
			std::cout << "Ошибка! Вы ввели число больше 1.";
			exit(-3);
		}
	};
	
	float healthOrc;
	std::cout << "Введите здоровье орка: ";
	std::cin >> healthOrc;

	checkValue(healthOrc);

	float resistOrc;
	std::cout << "Введите сопротивление магии: ";
	std::cin >> resistOrc;

	checkValue(resistOrc);

	do {
		float damageToOrc;
		std::cout << "Введите наносимый урон по орку: ";
		std::cin >> damageToOrc;

		checkValue(damageToOrc);

		damageToOrc -= damageToOrc * resistOrc;
		healthOrc -= damageToOrc;

		if (healthOrc < 0) {
			healthOrc = 0;
		}

		std::cout << std::format("Нанесен урон по орку в размере {:g}, оставшееся здоровье орка {:g}.", damageToOrc, healthOrc)
			      << "\n";

	} while (healthOrc > 0);

	std::cout << "Орк побежден! Поздравляем!!!" << "\n";

	return 0;
}