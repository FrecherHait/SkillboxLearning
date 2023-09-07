#include <iostream>
#include <vector>
#include <cmath>

int main() {

	// Для вывода русских символов в консоль Visual Studio
	setlocale(LC_ALL, "ru_RU.utf8");          
  
	std::cout << "----Практическое задание для модуля 8 \"Числа с плавающей запятой. Математические вычисления\"----" << "\n";
	std::cout << "---------------------Задание 3 \"Игрушечная история\"---------------------" << "\n";

  auto checkValue = [&](float val) {
      if (std::cin.fail() || std::cin.peek() != '\n')
      {
        std::cout << "Ошибка! Вы ввели не число." << "\n";
        exit(-1);
      }
      else if (val < 5) {
        std::cout << "Ошибка! Вы ввели число меньше 5.";
        exit(-2);
      }
    };

  float sizeX, sizeY, sizeZ;
  std::cout << "Введите размеры бруска:" << "\n";
  std::cout << "X: ";
  std::cin >> sizeX;

  checkValue(sizeX);

  std::cout << "Y: ";
  std::cin >> sizeY;

  checkValue(sizeY);

  std::cout << "Z: ";
  std::cin >> sizeZ;

  checkValue(sizeZ);

  float totalImpossibleCube = std::floor(sizeX / 5.f) * std::floor(sizeY / 5.f) * std::floor(sizeZ / 5.f);
  std::cout << "Из этого можно изготовить " 
            << totalImpossibleCube << " кубиков" << "\n";

  if (totalImpossibleCube >= 8) {
    int packOfCube = 0;

    for (int counterPow = 2; std::pow(counterPow, 3) < totalImpossibleCube; counterPow++) {
      packOfCube = std::pow(counterPow, 3);
    }

    std::cout << "Из этого количества кубиков можно создать набор из " 
              << packOfCube << " кубиков" << "\n";
  }
  else {
    std::cout << "Из этого количества кубиков нельзя создать набор" << "\n";
  }

  return 0;  
}