#include <iostream>
#include <vector>
#include <cmath>

int main() {

	// Для вывода русских символов в консоль Visual Studio
	setlocale(LC_ALL, "ru_RU.utf8");          
  
	std::cout << "----Практическое задание для модуля 8 \"Числа с плавающей запятой. Математические вычисления\"----" << "\n";
	std::cout << "---------------------Задание 5 \"Кенийский бегун\"---------------------" << "\n";

  auto checkValue = [&](float val) {
      if (std::cin.fail() || std::cin.peek() != '\n')
      {
        std::cout << "Ошибка! Вы ввели не число." << "\n";
        exit(-1);
      }
      else if (val <= 0) {
        std::cout << "Ошибка! Вы ввели некорректное число." << "\n";
        exit(-2);
      }
    };

  int totalKilometers;
  std::cout << "Привет, Сэм! Сколько километров ты сегодня пробежал? ";
  std::cin >> totalKilometers;

  checkValue(totalKilometers);

  float totalAccuracyRun = 0.f;

  for (int currentRound = 1; currentRound <= totalKilometers ; currentRound++) {
    int currentAccuracyRun;
    std::cout << "Какой у тебя был темп на километре " << currentRound << "? ";
    std::cin >> currentAccuracyRun;

    if (currentAccuracyRun <= 0) {
      std::cout << "Ошибка записи данных! Неверное значение." << "\n";
      currentRound--;
      continue;
    }

    totalAccuracyRun += currentAccuracyRun;
  }

  int totalTime = std::round(totalAccuracyRun / totalKilometers);

  std::cout << "Твой средний темп за тренировку: "
            << totalTime / 60 << " минуты " 
            << totalTime % 60 << " секунд." 
            << "\n";

  return 0;
}