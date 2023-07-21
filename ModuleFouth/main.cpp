#include <iostream>

void objectiveFirst() {
	int a;
	int b;

	std::cout << "Введите первое число: ";
	std::cin >> a;

	std::cout << "Введите второе число: ";
	std::cin >> b;

	std::cout << "-----Проверяем-----" << "\n";
	if (a < b) {
		std::cout << "Наименьшее число: " << a << "\n";
	}
	else if (a > b) {
		std::cout << "Наименьшее число: " << b << "\n";
	}
	else {
		std::cout << "Числа равны.";
	}
}

void objectiveSecond() {
	int a;
	int b;
	int sum;

	std::cout << "Введите первое число: ";
	std::cin >> a;

	std::cout << "Введите второе число: ";
	std::cin >> b;

	std::cout << "Введите сумму чисел: ";
	std::cin >> sum;
	
	std::cout << "-----Проверяем-----" << "\n";
	if (sum == a + b) {
		std::cout << "Верно!";
	}
	else {
		std::cout << "Ошибка! Верный результат: " << a + b;
	}
}

void objectiveThird() {
	int a;

	std::cout << "Введите число: ";
	std::cin >> a;

	std::cout << "-----Проверяем-----" << "\n";
	if (a % 2 == 0) {
		std::cout << "Число четное.";
	}
	else {
		std::cout << "Число нечетное.";
	}
}

void objectiveFouth() {
	int level = 1;
	int experience;

	std::cout << "Введите количество опыта: ";
	std::cin >> experience;

	std::cout << "-----Считаем-----" << "\n";
	if (experience >= 1000 && experience < 2500) {
		level = 2;
	}
	else if (experience >= 2500 && experience < 5000) {
		level = 3;
	}
	else if (experience >= 5000) {
		level = 4;
	}

	std::cout << "Ваш уровень: " << level;
}

void objectiveFifth() {
	int a;
	int b;

	std::cout << "Введите первое число: ";
	std::cin >> a;

	std::cout << "Введите второе число: ";
	std::cin >> b;

	std::cout << "-----Проверяем-----" << "\n";
	if (a % b == 0) {
		std::cout << "Да, " << a << " делится на " << b << " без остатка!";
	}
	else {
		std::cout << "Нет, " << a << " не делится на " << b << " без остатка!";
	}
}

int main() {
	setlocale(LC_ALL, "ru_RU.utf8");          // Для вывода русских символов в консоль Visual Studio

	std::cout << "----Практическое задание для модуля 3 \"Ввод данных пользователя.Строки\"----\n";
	
	while (true) {
		int cmdNum; // Переменная для ввода номера команд
		std::cout << "\n";
		std::cout << "1 - Задание 1 \"Минимум из двух чисел\"" << "\n";
		std::cout << "2 - Задание 2 \"Складываем в уме\"" << "\n";
		std::cout << "3 - Задание 3 \"Проверка на чётное число\"" << "\n";
		std::cout << "4 - Задание 4 \"Калькулятор опыта\"" << "\n";
		std::cout << "4 - Задание 5 \"Кратность числа\"" << "\n";
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
		}
	}
}