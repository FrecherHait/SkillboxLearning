#include <iostream>
#include <cmath>

int main() {
    // Для вывода русских символов в консоль Visual Studio
    setlocale(LC_ALL, "ru_RU.utf8");

    std::cout << "----Практическое задание для модуля 8 \"Числа с плавающей запятой. Математические вычисления\"----"
              << "\n";
    std::cout << "---------------------Задание 10 \"Тяжело в учении, легко в бою\"---------------------" << "\n";

    auto checkValue = [&](double val) {
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Ошибка! Вы ввели не число." << "\n";
            exit(-1);
        }
        else if (val < 0) {
            std::cout << "Число не может быть отрицательным." << "\n";
            exit (-2);
        }
    };

    double firstNum;
    std::cout << "Введите первое число: ";
    std::cin >> firstNum;
    checkValue(firstNum);

    double secondNum;
    std::cout << "Введите второе число: ";
    std::cin >> secondNum;
    checkValue(secondNum);

    double calculate = (std::fabs(firstNum + secondNum) / 2) + (std::fabs(firstNum - secondNum) / 2);

    std::cout << "Наибольшее число: " << calculate;

    return 0;
}
