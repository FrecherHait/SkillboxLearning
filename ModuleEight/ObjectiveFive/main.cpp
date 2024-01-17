#include <iostream>
#include <vector>
#include <cmath>

int main() {

	// Для вывода русских символов в консоль Visual Studio
	setlocale(LC_ALL, "ru_RU.utf8");          
  
	std::cout << "----Практическое задание для модуля 8 \"Циклы for и алгоритмы на циклах\"----" << "\n";
	std::cout << "---------------------Задание 5 \"Темп бега\"---------------------" << "\n";

  auto checkValue = [&](float val) {
      if (std::cin.fail() || std::cin.peek() != '\n')
      {
        std::cout << "Ошибка! Вы ввели не число." << "\n";
        exit(-1);
      }
      else if (val <= 0) {
        std::cout << "Ошибка! Вы ввели отрицательное число." << "\n";
        exit(-2);
      }
    };

  int rounds;
  std::cout << "Сколько кругов ты пробежал сегодня? ";
  std::cin >> rounds;

  float totalAccuracyRun = 0.f;

  for (int currentRound = 1; currentRound <= 6 ; currentRound++) {
    int currentAccuracyRun;
    std::cout << "Какой темп бега на круге " << currentRound << "? ";
    std::cin >> currentAccuracyRun;

    if (currentAccuracyRun <= 0) {
      std::cout << "Ошибка записи данных! Неверное значение." << "\n";
      currentRound--;
      continue;
    }

    totalAccuracyRun += currentAccuracyRun;
  }

  int totalTime = std::round(totalAccuracyRun / rounds);

  std::cout << totalTime / 60 << " min " 
            << totalTime % 60 << " sec";
  return 0;
}