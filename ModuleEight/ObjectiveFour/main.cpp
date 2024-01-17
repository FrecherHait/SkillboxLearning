#include <iostream>
#include <vector>
#include <cmath>

int main() {

	// Для вывода русских символов в консоль Visual Studio
	setlocale(LC_ALL, "ru_RU.utf8");          
  
	std::cout << "----Практическое задание для модуля 8 \"Циклы for и алгоритмы на циклах\"----" << "\n";
	std::cout << "---------------------Задание 4 \"Убийца Steam\"---------------------" << "\n";

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

  float fileSize;
  std::cout << "Введите размер файла: ";
  std::cin >> fileSize;

  float downloadSpeed;
  std::cout << "Введите скорость загрузки: ";
  std::cin >> downloadSpeed;

  for (struct { int seconds = 1; float currentDownload = 0.f;} progress; progress.currentDownload != fileSize; progress.seconds++) {
    progress.currentDownload += downloadSpeed;
    if (progress.currentDownload > fileSize) {
      progress.currentDownload = fileSize;
    }

    int percentProgress = (progress.currentDownload / fileSize) * 100;
    std::cout << "Всего загружено " << progress.currentDownload << " из " << fileSize << "(" << percentProgress << "%)" << "\n"; 
  }

  return 0;
}