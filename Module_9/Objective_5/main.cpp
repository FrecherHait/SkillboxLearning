#include <iostream>
#include <cmath>
#include <vector>
int main() {
    // Для вывода русских символов в консоль Visual Studio
    setlocale(LC_ALL, "ru_RU.utf8");

    std::cout << "----Практическое задание для модуля 9 \"Строки и текстовые данные. Базовые алгоритмы со строками\"----"
              << "\n";
    std::cout << "---------------------Задание 5 \"Из обычных чисел — в римские\"---------------------" << "\n";

    auto checkValue = [&](int val) {
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cout << "Ошибка! Вы ввели не число." << "\n";
            exit(-1);
        }
        else if (val < 1 || val > 3999) {
            std::cout << "Ошибка! Вы вышли из диапазона [1, 3999]." << "\n";
            exit(-2);
        }
    };

    std::vector<std::pair<std::string, int>> romanNumbers;
    romanNumbers.emplace_back("M", 1000);
    romanNumbers.emplace_back("CM", 900);
    romanNumbers.emplace_back("D", 500);
    romanNumbers.emplace_back("CD", 400);
    romanNumbers.emplace_back("C", 100);
    romanNumbers.emplace_back("XC", 90);
    romanNumbers.emplace_back("L", 50);
    romanNumbers.emplace_back("XL", 40);
    romanNumbers.emplace_back("X", 10);
    romanNumbers.emplace_back("IX", 9);
    romanNumbers.emplace_back("V", 5);
    romanNumbers.emplace_back("IV", 4);
    romanNumbers.emplace_back("I", 1);

    int number;
    std::cout << "Введите число: ";
    std::cin >> number;
    checkValue(number);

    for (auto &elem : romanNumbers) {
        int processSearch = number / elem.second;

        if (processSearch) {
            processSearch = number;

            while(processSearch >= elem.second) {
                processSearch -= elem.second;
                std::cout << elem.first;
            }
            number %= elem.second;
        }
    }

    return 0;
}
