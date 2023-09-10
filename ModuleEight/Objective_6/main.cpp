#include <iostream>
#include <vector>
#include <cmath>

int main() {

    // Для вывода русских символов в консоль Visual Studio
    setlocale(LC_ALL, "ru_RU.utf8");

    std::cout << "----Практическое задание для модуля 8 \"Числа с плавающей запятой. Математические вычисления\"----"
              << "\n";
    std::cout << "---------------------Задание 6 \"Маятник\"---------------------" << "\n";

    auto checkValue = [&](float val) {
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

    float beginAmplitude;
    std::cout << "Введите начальную амплитуду колебаний(см): ";
    std::cin >> beginAmplitude;

    checkValue(beginAmplitude);

    float endAmplitude;
    std::cout << "Введите конечную амплитуду колебаний(см): ";
    std::cin >> endAmplitude;

    checkValue(endAmplitude);

    if (beginAmplitude <= endAmplitude) {
        std::cout << "Ошибка! Вы ввели начальное значение, меньше чем конечное, либо равное ему.";
        return -5;
    }

    int counterAmplitude = 0;

    while (beginAmplitude > endAmplitude) {
        beginAmplitude *= 0.916f;
        counterAmplitude++;
    }

    std::cout << "Количество затуханий маятника: " << counterAmplitude << "\n";

    return 0;
}