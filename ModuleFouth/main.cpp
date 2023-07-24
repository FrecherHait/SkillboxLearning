#include <iostream>
#include <vector>

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

void objectiveSixth() {
	int men;
	int barbers;
	int requiredBarbersCount;

	std::cout << "Введите число мужчин: ";
	std::cin >> men;

	std::cout << "Введите число барберов: ";
	std::cin >> barbers;

	// я решил не заводить переменных под 8-часовую смену и 30 рабочим дням в месяц
	// так как они в условии задачи, являются константами
	//requiredBarbersCount = men / (8 * 30);


	int mansPerBarber = 8; // один человек в час, смена 8 часов
	// Сколько человек успеет постричь барбер за месяц?
	int mansPerBarberPerMonth = mansPerBarber * 30;
	std::cout << "Один барбер стрижет столько клиентов в месяц " << mansPerBarberPerMonth << "\n";

	// Сколько нужно барберов, чтобы постричь mansCount человек?
	requiredBarbersCount = men /  mansPerBarberPerMonth;
	
	if (requiredBarbersCount * mansPerBarberPerMonth < men) {
		requiredBarbersCount += 1;
	}
	
	std::cout << "Необходимое число барберов: " << requiredBarbersCount << "\n";

	if (requiredBarbersCount < 1) {
		std::cout << "Барберов хватает.";
	}
	else if (requiredBarbersCount == 1 && men % (barbers * mansPerBarberPerMonth) == 0) {
		std::cout << "Барберов ровно столько сколько нужно.";
	}
	else {
		std::cout << "Нихуя барберов не хватит!";
	}
}

void objectiveSeventh() {
	int numberDayForWeek;

	// для удобства заведу вектор, чтобы не копипастить постоянно дни недели
	// они будут вызываться по номеру недели
	std::vector<std::string> dayForWeek = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
 
	std::cout << "Введите день недели (от 1 до 7): ";
	std::cin >> numberDayForWeek;

	std::cout << "Меню сегодня(" << dayForWeek[numberDayForWeek - 1] << "):\n";

	switch (numberDayForWeek) {
		std::cout << "\n";
	case 1:
		std::cout << "Борщ" << "\n"
			      << "Салат \"Оливье\"" << "\n"
			      << "Макароны с сосиской" << "\n"
			      << "Лимонный чай" << "\n";
		break;
	case 2:
		std::cout << "Рассольник" << "\n"
			      << "Салат \"Винегрет\"" << "\n"
			      << "Гречневая каша с куриной котлетой" << "\n"
			      << "Яблочный сок" << "\n";
		break;
	case 3:
		std::cout << "Манная каша" << "\n"
			      << "Оладьи со сгущенкой" << "\n"
			      << "Какао" << "\n";
		break;
	case 4:
		std::cout << "Гороховый суп" << "\n"
				  << "Салат \"Цезарь\"" << "\n"
				  << "Куриная ножка с пюре" << "\n"
				  << "Морс" << "\n";
		break;
	case 5:
		std::cout << "Харчо" << "\n"
			      << "Салат \"Селедка под шубой\"" << "\n"
			      << "Баварские колбаски с капустой" << "\n"
			      << "Морс" << "\n";
		break;
	case 6:
		std::cout << "Пшенная каша" << "\n"
			      << "Творожная запеканка с малиновым джемом" << "\n"
				  << "Вишневый сок" << "\n";
		break;
	case 7:
		std::cout << "Солянка" << "\n"
				  << "Салат \"Мимоза\"" << "\n"
				  << "Стейк рибай с картофельным пюре" << "\n"
				  << "Кофе" << "\n";
		break;
	default:
		std::cout << "Вы ввели некорретный номер!" << "\n";
		break;
	}
}

int main() {

	// Для вывода русских символов в консоль Visual Studio
	setlocale(LC_ALL, "ru_RU.utf8");          

	std::cout << "----Практическое задание для модуля 3 \"Ввод данных пользователя.Строки\"----\n";
	
	while (true) {

		// Переменная для ввода номера команд
		int cmdNum; 
		std::cout << "\n";
		std::cout << "1 - Задание 1 \"Минимум из двух чисел\"" << "\n";
		std::cout << "2 - Задание 2 \"Складываем в уме\"" << "\n";
		std::cout << "3 - Задание 3 \"Проверка на чётное число\"" << "\n";
		std::cout << "4 - Задание 4 \"Калькулятор опыта\"" << "\n";
		std::cout << "5 - Задание 5 \"Кратность числа\"" << "\n";
		std::cout << "6 - Задание 6 \"Улучшим барберов\"" << "\n";
		std::cout << "7 - Задание 7 \"Меню ресторана\"" << "\n";
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
			objectiveSeventh();
		}
	}
}