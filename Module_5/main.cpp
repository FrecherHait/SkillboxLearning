#include <iostream>
#include <vector>

void objectiveFirst() {
	int speedPlain;
	int height;

	std::cout << "Введите текущую скорость самолета: ";
	std::cin >> speedPlain;

	std::cout << "Введите высоту полета: ";
	std::cin >> height;

	if ( (speedPlain >= 750 && speedPlain <= 850) && (height >= 9000 && height <= 9500) ) {
		std::cout << "Самолёт летит правильным эшелоном." << "\n";
	}
	else {
		std::cout << "Самолёт летит неверным эшелоном!" << "\n";
	}
}

void objectiveSecond() {
	int dayOfMay;

	std::cout << "Введите день мая: ";
	std::cin >> dayOfMay;

	int remainderOfDays = dayOfMay % 7;

	// проверяем на корректность введенного дня
	// P.S. Не люблю когда программы падают, вот и сделал лишнее действие, дабы исключить падения :)
	if (dayOfMay < 1 || dayOfMay > 31) {
		std::cout << "Вы ввели некорректный день мая!" << "\n";
	}
	else {

		// проверка на ноль является сообщением для программы, что это воскресенье, т.к.
		// нулевого дня не существует, говорим, что если у нас остаток 0, то это воскресенье
		// ибо делится нацело число, когда день мая оказывается воскресеньем
		if (remainderOfDays == 6 || remainderOfDays == 0) {
			std::cout << "День " << dayOfMay << " мая является выходным." << "\n";
			return;
		}
		else {
			if (dayOfMay <= 5 || (dayOfMay >= 8 && dayOfMay <= 10)) {
				std::cout << "День " << dayOfMay << " мая является выходным." << "\n";
			}
			else {
				std::cout << "День " << dayOfMay << " мая является рабочим." << "\n";
			}
		}
	}
	
}

void objectiveThird() {
	int dayOfMay;
	int beginDayOfWeek;
	
	std::cout << "Введите номер дня недели(например: 1 - понедельник, 2 - вторник и тд): ";
	std::cin >> beginDayOfWeek;
	
	std::cout << "Введите день мая: ";
	std::cin >> dayOfMay;
	
	// что бы программа не упала, если ввели не то число
	if ((dayOfMay >= 1 && dayOfMay <= 31) && (beginDayOfWeek >= 1 && beginDayOfWeek <= 7)) {
		int dayOfWeek;
		//операция по нахождению остатка дней недели
		{
			int remainderOfDays = dayOfMay % 7;
			dayOfWeek = (beginDayOfWeek + remainderOfDays - 1) % 7;
		}

		// делаем ту же проверку, что и во втором задании
		if (dayOfWeek == 6 || dayOfWeek == 0) {
			std::cout << "День " << dayOfMay << " мая является выходным." << "\n";
			return;
		}
		else {
			if (dayOfMay <= 5 || (dayOfMay >= 8 && dayOfMay <= 10)) {
				std::cout << "День " << dayOfMay << " мая является выходным." << "\n";
			}
			else {
				std::cout << "День " << dayOfMay << " мая является рабочим." << "\n";
			}
		}

	}
	else {
		std::cout << "Введен некорректный день мая или день недели!";
	}
	
}

void objectiveFouth() {
	struct SizeBox {
		int x;
		int y;
		int z;
	} boxABC{}, boxMNK{};

	std::cout << "Введите размеры первой коробки (AxBxC): ";
	std::cin >> boxABC.x >> boxABC.y >> boxABC.z;

	std::cout << "Введите размеры второй коробки (MxNxK): ";
	std::cin >> boxMNK.x >> boxMNK.y >> boxMNK.z;

	// Создаем массив всех возможных комбинаций сторон первой коробки
	int sizeBoxABC[3][3] = { {boxABC.x, boxABC.y, boxABC.z}, 
							 {boxABC.x, boxABC.z, boxABC.y}, 
							 {boxABC.y, boxABC.x, boxABC.z} };

	// Создаем массив размера второй коробки
	int sizeBoxMNK[] = { boxMNK.x, boxMNK.y, boxMNK.z };

	// Лямба-функция для проверки всех возможныx комбинаций сторон первой коробки относительно второй коробки
	auto checkBoxFit = [&](int sizeBox1[3][3], int sizeBox2[]) -> bool {
		for (int i = 0; i < 3; ++i) {
			if ((sizeBox1[i][0] <= sizeBox2[0]) && (sizeBox1[i][1] <= sizeBox2[1]) && (sizeBox1[i][2] <= sizeBox2[2])) {
				return true;
			}
		}
		return false;
	};

	if (checkBoxFit(sizeBoxABC, sizeBoxMNK)) {
		std::cout << "Первая коробка помещается внутрь второй коробки." << std::endl;
	}
	else {
		std::cout << "Первую коробку нельзя положить внутрь второй коробки." << std::endl;
	}
}

void objectiveFifth() {
	int money;
	std::vector<int> banknotes = {5000, 2000, 1000, 500, 200, 100};
	
	std::cout << "Введите сумму, которую хотите вывести(не более 150 000 за раз): ";
	std::cin >> money;

	if (money < 100 || money > 150000) {
		std::cout << "Выдать купюры невозмозно. Сумма меньше 100 рублей или больше 150 000 рублей!" << "\n";
	}
	else if (money % 100 != 0) {
		std::cout << "Выдать купюры невозможно. Введена сумма не кратная 100 рублям!" << "\n";
	}
	else {
		std::cout << "Следующие купюры: ";
		for (auto& currentBanknote : banknotes) {
			int banknotesCounter = money / currentBanknote;

			if (banknotesCounter != 0) {			
				money %= currentBanknote;
				std::cout << banknotesCounter << " по " << currentBanknote << ", ";
			}
		}
		std::cout << "успешно выданы." << "\n";
	}
}

void objectiveSixth() {
	struct Date {
		int day;
		int month;
		int year;
	} birthday{}, currentDay{};

	std::cout << "Введите дату рождения покупателя через пробел(Пример: 05 08 2023): ";
	std::cin >> birthday.day >> birthday.month >> birthday.year;

	std::cout << "Введите сегодняшнюю дату: ";
	std::cin >> currentDay.day >> currentDay.month >> currentDay.year;

	{
		auto checkPermissionSellAlcohol = [&](int age) {
			if (age >= 18) {
				std::cout << "Алкоголь можно продавать.";
			}
			else {
				std::cout << "Алкоголь нельзя продвать.";
			}
		};

		if ((birthday.month > currentDay.month) ||
			(birthday.month == currentDay.month && birthday.day >= currentDay.day)) {
			checkPermissionSellAlcohol(currentDay.year - birthday.year - 1);
		}
		else {
			checkPermissionSellAlcohol(currentDay.year - birthday.year);
		}
	}
}

int main() {

	// Для вывода русских символов в консоль Visual Studio
	setlocale(LC_ALL, "ru_RU.utf8");          

	std::cout << "----Практическое задание для модуля 5 \"Логические операторы и сложные условия\"----\n";
	
	while (true) {

		// Переменная для ввода номера команд
		int cmdNum; 
		std::cout << "\n";
		std::cout << "1 - Задание 1 \"Полёт нормальный!\"" << "\n";
		std::cout << "2 - Задание 2 \"Майские!\"" << "\n";
		std::cout << "3 - Задание 3 \"Майские — усложнение\"" << "\n";
		std::cout << "4 - Задание 4 \"Усложнение задачи про кирпич\"" << "\n";
		std::cout << "5 - Задание 5 \"Банкомат-2\"" << "\n";
		std::cout << "6 - Задание 6 \"Грустное совершеннолетие\"" << "\n";
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