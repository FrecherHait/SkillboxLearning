#include <iostream>
#include <vector>

void objectiveFirst() {
	int time;
	std::cout << "Введите, который час: ";
	std::cin >> time;

	if (time < 0 || time > 23) {
		std::cout << "Вы ввели отрицательное число или число больше 23" << "\n";
		return;
	}
	else if (time > 12) {
		time -= 12;
	}
	else if (time == 0) {
		time = 12;
	}

	for (int counter = 0; counter < time; counter++)
		std::cout << "Ку-ку!" << "\n";
}

void objectiveSecond() {
	int number;
	std::cout << "Введите число: ";
	std::cin >> number;

	if (number < 0) {
		std::cout << "Вы ввели отрицательное число." << "\n0";
		return;
	} 
	else {
		int counter = 1;
		while (number /= 10) {
			counter++;
		}
		std::cout << "Цифр в числе: " << counter << "\n";
	}
}

void objectiveThird() {
	
}

void objectiveFouth() {

}

void objectiveFifth() {

}

void objectiveSixth() {

}

int main() {

	// Для вывода русских символов в консоль Visual Studio
	setlocale(LC_ALL, "ru_RU.utf8");          

	std::cout << "----Практическое задание для модуля 6 \"Введение в циклы: while, do while, break\"----\n";
	
	while (true) {

		// Переменная для ввода номера команд
		int cmdNum; 
		std::cout << "\n";
		std::cout << "1 - Задание 1 \"Кукушка\"" << "\n";
		std::cout << "2 - Задание 2 \"Слишком большие числа\"" << "\n";
		std::cout << "3 - Задание 3 \"Коллекторы\"(в процессе)" << "\n";
		std::cout << "4 - Задание 4 \"Счастливый билетик\"(в процессе)" << "\n";
		std::cout << "5 - Задание 5 \"Числа Фибоначчи\"(в процессе)" << "\n";
		std::cout << "6 - Задание 6 \"Вклады\"(в процессе)" << "\n";
		std::cout << "0 - Выход" << "\n";
		std::cout << "Введите номер команды: ";
		std::cin  >> cmdNum;

		switch (cmdNum) {
		case 0:
			return 0;
		case 1:
			objectiveFirst();
			break;
		case 2:
			objectiveSecond();
			break;
		case 3:
			objectiveThird();
			break;
		case 4:
			objectiveFouth();
			break;
		case 5:
			objectiveFifth();
			break;
		case 6:
			objectiveSixth();
			break;
		}
	}
}