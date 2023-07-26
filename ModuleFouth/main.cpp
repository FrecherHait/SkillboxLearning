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
	int menCount;
	int barbersCount;
	int shiftTimePerMonth;

	std::cout << "************** Барбершоп-калькулятор **************\n";
	std::cout << "Введите число мужчин в городе: ";
	std::cin >> menCount;

	std::cout << "Сколько уже барберов удалось нанять? ";
	std::cin >> barbersCount;

	// Сколько человек может постричь один барбер за одну смену?
	int mansPerBarber = 8; // один человек в час, смена 8 часов

	// Сколько человек успеет постричь барбер за месяц?
	int mansPerBarberPerMonth = mansPerBarber * 30;

	std::cout << "Один барбер стрижет столько клиентов в месяц " << mansPerBarberPerMonth << "\n";

	int requiredBarbersCount = menCount / mansPerBarberPerMonth;

	shiftTimePerMonth = menCount % mansPerBarberPerMonth;

	if (shiftTimePerMonth != 0) {
		requiredBarbersCount += 1;
	}

	std::cout << "Необходимое число барберов: " << requiredBarbersCount << "\n";

	// Сколько человек успеют посчтричь requiredBarbersCount за месяц?
	std::cout << requiredBarbersCount << " барбера могут постричь "
		      << requiredBarbersCount * mansPerBarberPerMonth << " мужчин за месяц.\n";

	// Сравниваем с количеством имеющихся барберов
	if (requiredBarbersCount > barbersCount) {
		std::cout << "Нужно больше барберов!!!\n";
	}
	else if (requiredBarbersCount == barbersCount) {
		std::cout << "Барберов ровно столько, сколько нужно!!!\n";
	}

	if (barbersCount > requiredBarbersCount * 2) {
		std::cout << "У вас работает в два раза больше барберов, чем это нужно!!!\n";
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

	if (numberDayForWeek == 1) {
		std::cout << "Борщ" << "\n"
				  << "Салат \"Оливье\"" << "\n"
				  << "Макароны с сосиской" << "\n"
				  << "Лимонный чай" << "\n";
	}
	else if (numberDayForWeek == 2) {
		std::cout << "Рассольник" << "\n"
				  << "Салат \"Винегрет\"" << "\n"
				  << "Гречневая каша с куриной котлетой" << "\n"
				  << "Яблочный сок" << "\n";
	}
	else if (numberDayForWeek == 3) {
		std::cout << "Манная каша" << "\n"
				  << "Оладьи со сгущенкой" << "\n"
				  << "Какао" << "\n";
	}
	else if (numberDayForWeek == 4) {
		std::cout << "Гороховый суп" << "\n"
				  << "Салат \"Цезарь\"" << "\n"
				  << "Куриная ножка с пюре" << "\n"
				  << "Морс" << "\n";
	}
	else if (numberDayForWeek == 5) {
		std::cout << "Харчо" << "\n"
				  << "Салат \"Селедка под шубой\"" << "\n"
				  << "Баварские колбаски с капустой" << "\n"
				  << "Морс" << "\n";
	}
	else if (numberDayForWeek == 6) {
		std::cout << "Пшенная каша" << "\n"
				  << "Творожная запеканка с малиновым джемом" << "\n"
				  << "Вишневый сок" << "\n";
	}
	else if (numberDayForWeek == 7) {
		std::cout << "Солянка" << "\n"
				  << "Салат \"Мимоза\"" << "\n"
				  << "Стейк рибай с картофельным пюре" << "\n"
				  << "Кофе" << "\n";
	}
	else {
		std::cout << "Вы ввели некорретный номер!" << "\n";
	}
}

void objectiveEighth() {
	int salaryFirstWorker;
	int salarySecondWorker;
	int salaryThirdWorker;
	int minSalaryWorkers;
	int maxSalaryWorkers;
	int differenceSalary;
	int avgSalaryWorkers;

	std::cout << "Введите зарплату первого сотрудника: ";
	std::cin  >> salaryFirstWorker;

	std::cout << "Введите зарплату второго сотрудника: ";
	std::cin >> salarySecondWorker;

	std::cout << "Введите зарплату третьего сотрудника: ";
	std::cin >> salaryThirdWorker;

	std::cout << "-----Считаем-----" << "\n";

	minSalaryWorkers = salaryFirstWorker;
	maxSalaryWorkers = salaryFirstWorker;

	if (salaryFirstWorker > salarySecondWorker && salaryFirstWorker > salaryThirdWorker) {
		maxSalaryWorkers = salaryFirstWorker;
	}
	else if (salaryFirstWorker < salarySecondWorker && salaryFirstWorker < salaryThirdWorker) {
		minSalaryWorkers = salaryFirstWorker;
	}

	if (salarySecondWorker > salaryFirstWorker && salarySecondWorker > salaryThirdWorker) {
		maxSalaryWorkers = salarySecondWorker;
	}
	else if (salarySecondWorker < salaryFirstWorker && salarySecondWorker < salaryThirdWorker) {
		minSalaryWorkers = salarySecondWorker;
	}
	
	if (salaryThirdWorker > salaryFirstWorker && salaryThirdWorker > salarySecondWorker) {
		maxSalaryWorkers = salaryThirdWorker;
	}
	else if (salaryThirdWorker < salaryFirstWorker && salaryThirdWorker < salarySecondWorker) {
		minSalaryWorkers = salaryThirdWorker;
	}

	std::cout << "Самая высокая зарплата в отделе: " << maxSalaryWorkers << "\n";

	differenceSalary = maxSalaryWorkers - minSalaryWorkers;

	std::cout << "Разница между самой высокой и самой низкой зарплатой в отделе: " << differenceSalary << "\n";

	avgSalaryWorkers = (salaryFirstWorker + salarySecondWorker + salaryThirdWorker) / 3;

	std::cout << "Средняя зарплата в отделе: " << avgSalaryWorkers;
}

void objectiveNinth() {
	int salary;
	int tax = 0;

	std::cout << "Введите ваш доход: ";
	std::cin >> salary;

	if (salary > 50000) {
		tax = 0.3 * (salary - 50000) + 0.2 * (50000 - 10000) + 0.13 * 10000;
	}
	else if (salary < 50000 && salary > 10000) {
		tax = 0.2 * (salary - 10000) + 0.13 * 10000;
	}
	else if (salary < 10000 && salary > 0) {
		tax = 0.13 * salary;
	}
	else {
		std::cout << "Вы ничего не заработали или ввели отрицательный доход." << "\n";
	}
	std::cout << tax;
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
		std::cout << "8 - Задание 8 \"Зарплата\"" << "\n";
		std::cout << "9 - Задание 9 \"Прогрессивный налог\"" << "\n";
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
			break;
		case 8:
			objectiveEighth();
			break;
		case 9:
			objectiveNinth();
			break;
		}
	}
}