#include <iostream>
#include <cmath>

int main() {
    // Для вывода русских символов в консоль Visual Studio
    setlocale(LC_ALL, "ru_RU.utf8");

    std::cout << "----Практическое задание для модуля 8 \"Числа с плавающей запятой. Математические вычисления\"----"
              << "\n";
    std::cout << "---------------------Задание 9 \"Яйца\"---------------------" << "\n";

    auto checkValue = [&](double val) {
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cout << "Ошибка! Вы ввели не число." << "\n";
            exit(-1);
        }
        else if (val <= 0) {
            std::cout << "Ошибка! Вы ввели некорретное число." << "\n";
            exit(-2);
        }
    };

    double maxLevelDangerous;
    std::cout << "Введите максимально допустимый уровень опасности: ";
    std::cin >> maxLevelDangerous;
    checkValue(maxLevelDangerous);

    double minLevelDepth = 0;
    double maxLevelDepth = 4;
    double currentLevelDepth;

    while (true) {
        currentLevelDepth = (minLevelDepth + maxLevelDepth) / 2;
        double currentLevelDangerous = std::pow(currentLevelDepth, 3) - (3 * std::pow(currentLevelDepth, 2)) - (12 * currentLevelDepth) + 10;;

        if (std::abs(currentLevelDangerous) <= maxLevelDangerous)
            break;
        else if (currentLevelDangerous > 0)
            minLevelDepth = currentLevelDepth;
        else
            maxLevelDepth = currentLevelDepth;
    }

    std::cout << "Приблизительная глубина безопасной кладки: " << currentLevelDepth;

    return 0;
}
