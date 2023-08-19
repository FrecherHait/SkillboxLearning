#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <variant>

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
	std::string nameDebtor;
	std::cout << "Введите имя должника: ";
	std::cin >> nameDebtor;

	int sumOfDebt;
	std::cout << "Введите сумму долга: ";
	std::cin >> sumOfDebt;

	if (sumOfDebt < 0) {
		std::cout << "Вы ввели отрицательную сумму долга" << "\n";
		return;
	}

	while (sumOfDebt > 0) {
		std::cout << "Ваш долг: " << sumOfDebt << " рублей" << "\n";

		int sunRepaymentDebt;
		std::cout << "Введите сумму для погашения доллга: ";
		std::cin >> sunRepaymentDebt;

		if (sumOfDebt < sunRepaymentDebt) {
			sumOfDebt -= sunRepaymentDebt;
			std::cout << "Ваш остаток на счете: " << sumOfDebt * (-1) << "\n";
		}
		else {
			sumOfDebt %= sunRepaymentDebt;
		}
	}

	std::cout << "Долг погашен!" << "\n";
}

/*
В старину, когда даже в столице билеты в общественном транспорте выдавали контролёры, существовало поверье: 
если на билете сумма первых трёх цифр в номере билета равна сумме трёх последних, то это к удаче. 
Напишите программу, которая получала бы на вход шестизначный номер билета и выводила, счастливый это билет или нет. 
К примеру, билеты 666 666 и 252 135 — счастливые, а 123 456 — нет.

Пример выполнения

			Введите номер билета: 123060
			Билет счастливый!
			Введите номер билета: 123040
			Повезёт в следующий раз!

Рекомендации по выполнению
Программу необходимо сделать так, чтобы можно было увеличить количество цифр в билете без особых изменений в коде.
Для получения младшего разряда числа (самой правой цифры) используйте выражение: one_digit = digits % 10.
Используйте циклы для подсчёта суммы цифр в номере билета.
*/
void objectiveFouth() {
	auto sumDigitsOfTicket = [&](int* number, int size) -> int {
		int result = 0;
		while (size > 0) {
			result += *number % 10;
			*number /= 10;
			size--;
		}
		return result;
	};

	int numberOfTicket;
	std::cout << "Введите номер билета: ";
	std::cin >> numberOfTicket;

	int size = std::to_string(numberOfTicket).length() / 2;
	int sumFirstHalfDigits = sumDigitsOfTicket(&numberOfTicket, size);
	int sumSecondHalfDigits = sumDigitsOfTicket(&numberOfTicket, size);

	if (sumFirstHalfDigits == sumSecondHalfDigits) {
		std::cout << "Билет счастливый!" << "\n";
	}
	else {
		std::cout << "Повезёт в следующий раз!" << "\n";
	}

}

void objectiveFifth() {
	auto fibonacci = [&](int N) -> int {
		if (N == 1 || N == 2) {
			return 1;
		}
		int result = 0;
		int previous1 = 1;
		int previous2 = 1;

		for (int i = 3; i <= N; i++) {
			result = previous1 + previous2;
			previous1 = previous2;
			previous2 = result;
		}

		return result;
	};

	int mumberFibonacci;
	std::cout << "Введите номер последовательности N: ";
	std::cin >> mumberFibonacci;

	if (mumberFibonacci <= 0) {
		std::cout << "Некорректный ввод N!" << "\n";
	}
	else {
		std::cout << "Число в последовательности: " << fibonacci(mumberFibonacci) << "\n";
	}
}

void objectiveSixth() {
	int contribution;
	std::cout << "Введите размер вклада: ";
	std::cin >> contribution;

	float percentegeContrib; // не знаю как корректно вычислять с int, поэтому использую float
	std::cout << "Введите процентную ставку: ";
	std::cin >> percentegeContrib;

	int finalSum;
	std::cout << "Введите желаемую сумму: ";
	std::cin >> finalSum;

	int years = 0;

	while (contribution < finalSum) {
		contribution += (percentegeContrib / 100) * contribution;
		years++;
	}

	std::cout << std::format("Придется подождать: {} лет\n", years);
}

void objectiveSeven() {
	auto deleteNegative = [&](int value) -> int {
		if (value < 0) {
			return value * (-1);
		}

		return value;
	};

	int numerator;
	std::cout << "Введите числитель: ";
	std::cin >> numerator;

	int denomerator;
	std::cout << "Введите знаменатель: ";
	std::cin >> denomerator;

	int div = 2;

	int maxNumber = std::max(deleteNegative(numerator), deleteNegative(denomerator));

	while (div <= maxNumber) {
		if (!(numerator % div) && !(denomerator % div)) {
			numerator /= div;
			denomerator /= div;
			continue;
		}
		div++;
	}

	if ((numerator < 0 && denomerator < 0) || denomerator < 0) {
		numerator /= -1;
		denomerator /= -1;
	}

	std::cout << std::format("Результат: {} / {}", numerator, denomerator);
}

void objectiveEight() {

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
		std::cout << "3 - Задание 3 \"Коллекторы\"" << "\n";
		std::cout << "4 - Задание 4 \"Счастливый билетик\"" << "\n";
		std::cout << "5 - Задание 5 \"Числа Фибоначчи\"" << "\n";
		std::cout << "6 - Задание 6 \"Вклады\"" << "\n";
		std::cout << "6 - Задание 7 \"Сокращение дроби (дополнительное задание)\"" << "\n";
		std::cout << "6 - Задание 8 \"Угадай число (дополнительное задание)\"" << "\n";
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
		case 7:
			objectiveSeven();
			break;
		case 8:
			break;
		}
	}
}