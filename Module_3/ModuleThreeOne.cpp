#include "ModuleThreeOne.h"
#include <iostream>
ModuleThreeOne::ModuleThreeOne() {
	totalPassengers = 0;
	totalMoney      = 0;
	inPassengers    = 0;
	outPassengers   = 0;
	salaryDriver    = 0;
	fuel            = 0;
	taxes           = 0;
	repair          = 0;
	profit          = 0;
	stop            = "";
}

void ModuleThreeOne::run() {

	stop = "Улица программистов";

	std::cout << "Прибываем на остановку \"" << stop << "\". В салоне пассажиров: " << totalPassengers << "\n";
	std::cout << "Введите количество вошедщих пассажиров: ";
	std::cin  >> inPassengers;

	std::cout << "Введите количество вышедших пассажиров: ";
	std::cin  >> outPassengers;

	totalPassengers += inPassengers;
	totalPassengers -= outPassengers;
	totalMoney      += inPassengers * 20;

	std::cout << "Сколько пассажиров вышло? " << outPassengers << "\n";
	std::cout << "Сколько пассажиров зашло на остановке? " << inPassengers << "\n";
	std::cout << "Отправляемся с остановки \"" << stop << "\". В салоне пассажиров: " << totalPassengers << "\n";
	std::cout << "-----------Едем---------\n\n";

	stop = "Проспект алгоритмов";

	std::cout << "Прибываем на остановку \"" << stop << "\". В салоне пассажиров: " << totalPassengers << "\n";
	std::cout << "Введите количество вошедщих пассажиров: ";
	std::cin  >> inPassengers;

	std::cout << "Введите количество вышедших пассажиров: ";
	std::cin  >> outPassengers;

	totalPassengers += inPassengers;
	totalPassengers -= outPassengers;
	totalMoney      += inPassengers * 20;

	std::cout << "Сколько пассажиров вышло? " << outPassengers << "\n";
	std::cout << "Сколько пассажиров зашло на остановке? " << inPassengers << "\n";
	std::cout << "Отправляемся с остановки \"" << stop << "\". В салоне пассажиров: " << totalPassengers << "\n";
	std::cout << "-----------Едем---------\n\n";

	stop = "Университет УлГУ";

	std::cout << "Прибываем на остановку \"" << stop << "\". В салоне пассажиров: " << totalPassengers << "\n";
	std::cout << "Введите количество вошедщих пассажиров: ";
	std::cin  >> inPassengers;

	std::cout << "Введите количество вышедших пассажиров: ";
	std::cin  >> outPassengers;

	totalPassengers += inPassengers;
	totalPassengers -= outPassengers;
	totalMoney      += inPassengers * 20;

	std::cout << "Сколько пассажиров вышло? " << outPassengers << "\n";
	std::cout << "Сколько пассажиров зашло на остановке? " << inPassengers << "\n";
	std::cout << "Отправляемся с остановки \"" << stop << "\". В салоне пассажиров: " << totalPassengers << "\n";
	std::cout << "-----------Едем---------\n\n";

	stop = "Проспект Гая";

	std::cout << "Прибываем на конечную остановку \"" << stop << "\". В салоне пассажиров: " << totalPassengers << "\n";

	//Здесь я опирался на гарантированный выход всех пассажиров на конечной остановке
	inPassengers     = 0;
	outPassengers    = totalPassengers;
	totalPassengers -= totalPassengers;

	std::cout << "Сколько пассажиров вышло? " << outPassengers << "\n";
	std::cout << "Сколько пассажиров зашло на остановке? " << inPassengers << "\n";
	std::cout << "В салоне пассажиров : " << totalPassengers << "\n";
	std::cout << "-----------Конечная---------\n\n";

	salaryDriver = totalMoney / 4;
	fuel         = totalMoney / 5;
	taxes        = totalMoney / 5;
	repair       = totalMoney / 5;
	profit       = totalMoney - (salaryDriver + fuel + taxes + repair);

	std::cout << "Всего заработали: "         << totalMoney << "\n";
	std::cout << "Зарплата водителя: "        << salaryDriver << "\n";
	std::cout << "Расходы на топливо: "       << fuel << "\n";
	std::cout << "Налоги: "                   << taxes << "\n";
	std::cout << "Расходы на ремонт машины: " << repair << "\n";
	std::cout << "Итого доход: "              << profit << "\n";
}

ModuleThreeOne::~ModuleThreeOne() {

}