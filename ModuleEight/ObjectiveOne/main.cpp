#include <iostream>
#include <format>
#include <cmath>

int main() {

	// Для вывода русских символов в консоль Visual Studio
	setlocale(LC_ALL, "ru_RU.utf8");          

	std::cout << "----Практическое задание для модуля 7 \"Циклы for и алгоритмы на циклах\"----" << "\n";
	std::cout << "---------------------Задание 1 \"Космический симулятор\"---------------------" << "\n";

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
	};

	float F;
	std::cout << "Введите силу тяги F: ";
	std::cin >> F;

	checkValue(F);

	float m;
	std::cout << "Введите массу звездолёта m: ";
	std::cin >> m;

	checkValue(m);

	float t;
	std::cout << "Введите время: ";
	std::cin >> t;

	checkValue(t);

	float distance = ((F / m) * std::pow(t, 2.f)) / 2;

	std::cout << std::format("Через {} сек космический корабль окажется на расстоянии  {:g} от первоначального положения.", t, distance)
		      << "\n";

	return 0;
}