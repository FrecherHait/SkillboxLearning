#include <iostream>
#include <vector>

int main() {
    // Для вывода русских символов в консоль Visual Studio
    setlocale(LC_ALL, "ru_RU.utf8");

    std::cout << "----Практическое задание для модуля 9 \"Строки и текстовые данные. Базовые алгоритмы со строками\"----"
              << "\n";
    std::cout << "---------------------Задание 2 \"Длинное вещественное число\"---------------------" << "\n";

    std::string floatNum;
    std::cout << "Введите число: ";
    std::cin >> floatNum;

    bool isValid = false;

    for (int i = 0, usePoint = 0; i < (int) floatNum.length(); i++) {

        if (i == 0 && floatNum[i] == '-')
            continue;
        else if (isdigit(floatNum[i])) {
            isValid = true;
            continue;
        }
        else if (floatNum[i] == '.' && !usePoint) {
            usePoint = 1;
            continue;
        }

        isValid = false;
        break;
    }

    if (isValid)
        std::cout << "Yes" << "\n";
    else
        std::cout << "No" << "\n";

    return 0;
}
