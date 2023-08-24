#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <iomanip>
#include <ctime>

void objectiveFirst() {
	int buckwheatKg = 100;
	int counterMounth = 1;

	std::cout << "Всего гречки было на начало подсчёта: 100 кг" << "\n";

	for (; buckwheatKg -= 4; counterMounth++) {		
		std::cout << std::format("После {} месяца у вас в запасе останется {} кг гречки\n", 
								 counterMounth, buckwheatKg);
	}

	std::cout << std::format("После {} месяца гречка закончится\n", counterMounth);
}

void objectiveSecond() {
	int quantityWater, quantityMilk; 
	int counterAmericano = 0, counterLatte = 0;
	int drinkCmd;

	std::cout << "Введите количество воды: ";
	std::cin >> quantityWater;

	std::cout << "Введите количество молока: ";
	std::cin >> quantityMilk;

	bool doAmericano = true, doLatte = true; // завел эти флаги для удобства читаемости кода

	// здесь можно было еще проверять так (quantityWater > 300) || (quantityWater > 30 && quantityMilk > 270)
	// но так как, по заданию нужно выводить чего конкретно не хватает, воды или молока, и в целом хватает ли ингридиентов,
	// то будет дубликация проверки
	// да и запись в условии была бы длинной, поэтому вот такая запись через флаги, как по мне, выглядит читабельнее
	while (doAmericano || doLatte) {
		std::cout << "Выберите напиток (1 — американо, 2 — латте): ";
		std::cin >> drinkCmd;

		switch (drinkCmd) {
		case 1:
			if (quantityWater < 300) {
				doAmericano = false;
				std::cout << "Не хватает воды." << "\n";
			}
			else {
				quantityWater -= 300;
				counterAmericano++;
				std::cout << "Ваш напиток готов" << "\n";
			}
			break;
		case 2:
			if (quantityWater < 30) {
				doLatte = false;
				std::cout << "Не хватает воды." << "\n";
			}
			else if (quantityMilk < 270) {
				doLatte = false;
				std::cout << "Не хватает молока." << "\n";
			}
			else {
				quantityWater -= 30;
				quantityMilk  -= 270;
				counterLatte++;
				std::cout << "Ваш напиток готов" << "\n";
			}
			break;
		default:
			std::cout << "Вы ввели неверный номер напитка. Допустимые номера напитков: 1 или 2" << "\n";
			break;
		}
	}

	std::cout << "***Отчёт***" << "\n";
	std::cout << std::format("            Вода: {} мл", quantityWater) << "\n";
	std::cout << std::format("            Молоко: {} мл", quantityMilk) << "\n";
	std::cout << "Кружек американо приготовлено: " << counterAmericano << "\n";
	std::cout << "Кружек латте приготовлено: " << counterLatte << "\n";
}

void objectiveThird() {
}

void objectiveFouth() {
	int width, height;
	std::cout << "Введите ширину и высоту рамки: ";
	std::cin >> width >> height;

	for (int counterHeight = 0; counterHeight < height; counterHeight++) {
		for (int counterWidth = 0; counterWidth < width; counterWidth++) {
			if (counterWidth == 0 || counterWidth + 1 == width) {
				std::cout << "|";
			}
			else if (counterHeight == 0 || counterHeight + 1 == height) {
				std::cout << "-";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

}

void objectiveFifth() {

}

void objectiveSixth() {

}

void objectiveSeven() {

}

void objectiveEight() {

}

int main() {

	// Для вывода русских символов в консоль Visual Studio
	setlocale(LC_ALL, "ru_RU.utf8");          

	std::cout << "----Практическое задание для модуля 7 \"Циклы for и алгоритмы на циклах\"----\n";
	
	while (true) {

		// Переменная для ввода номера команд
		int cmdNum; 
		std::cout << "\n";
		std::cout << "1 - Задание 1 \"Запасы продовольствия\"" << "\n";
		std::cout << "2 - Задание 2 \"Кофемашина\"" << "\n";
		std::cout << "3 - Задание 3 \"Красный Марс\"(в процессе)" << "\n";
		std::cout << "4 - Задание 4 \"Рамка\"" << "\n";
		std::cout << "5 - Задание 5 \"Координатные оси\"(в процессе)" << "\n";
		std::cout << "6 - Задание 6 \"Важные объявления\"(в процессе)" << "\n";
		std::cout << "7 - Задание 7 \"Биолаборатория (дополнительное задание)\"(в процессе)" << "\n";
		std::cout << "8 - Задание 8 \"Ёлочка (дополнительное задание)\"(в процессе)" << "\n";
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