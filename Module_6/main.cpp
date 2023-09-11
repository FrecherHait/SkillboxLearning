#include <iostream>
#include <vector>
#include <string>
#include <format>

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
	std::vector<std::string> answersPack = { "Yes", "yes","No", "no" };
	int minNumber = 0;
	int maxNumber = 63;
	int searchNumber;

	std::cout << "Добро пожаловать в \"Угадай число\"." << "\n"
			  << "Вы загадываете число от 0 до 63, а я попробую его угадать, задавая вопросы на которые нужно отвечать \"Yes\"(Да)"
			  << "или \"No\"(Нет)." << "\n"
			  << "Как загадаете, нажмите любую клавишу." << "\n";

	std::system("pause");

	while (minNumber <= maxNumber) {
		std::string answer;
		searchNumber = (minNumber + maxNumber) / 2;

		std::cout << std::format("Ваше число больше {}?\n", searchNumber);
		std::cin >> answer;

		if (std::find(answersPack.begin(), answersPack.end(), answer.c_str()) != answersPack.end()) {

			if (answer == "Yes" || answer == "yes") {
				minNumber = searchNumber + 1;
				searchNumber = minNumber;
			}
			else {
				maxNumber = searchNumber - 1;
				searchNumber = maxNumber;
			}

		}
		else {
			std::cout << "Вы ввели некорретный ответ! Пожалуйста, напишите Yes или No." << "\n";
		}
	}

	std::cout << std::format("Ваше число: {}\n", minNumber);
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
		std::cout << "7 - Задание 7 \"Сокращение дроби (дополнительное задание)\"" << "\n";
		std::cout << "8 - Задание 8 \"Угадай число (дополнительное задание)\"" << "\n";
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
			objectiveEight();
			break;
		}
	}
}