#include <iostream>
#include <cmath>
#include <regex>
int main() {
    // Для вывода русских символов в консоль Visual Studio
    setlocale(LC_ALL, "ru_RU.utf8");

    std::cout << "----Практическое задание для модуля 9 \"Строки и текстовые данные. Базовые алгоритмы со строками\"----"
              << "\n";
    std::cout << "---------------------Задание 4 \"Быки и коровы\"---------------------" << "\n";

    auto checkValue = [&](const std::string& val) {
        if (val.length() != 4) {
            std::cout << "Ошибка. Вы ввели не 4-х значное число!" << "\n";
            exit(-1);
        }
        else if (!std::regex_match(val, std::regex("[0-9]+"))) {
            std::cout << "Ошибка. Вы ввели некорретное число!" << "\n";
            exit(-2);
        }
    };

    std::string hiddenNumber;
    std::cout << "Введите задуманное число: ";
    std::cin >> hiddenNumber;

    checkValue(hiddenNumber);

    std::string tryNumber;
    std::cout << "Введите второе число: ";
    std::cin >> tryNumber;

    checkValue(tryNumber);

    int cow = 0;
    int bull = 0;

    for(int i = 0; i < 4; i++) {
        if (hiddenNumber[i] == tryNumber[i]) {
            hiddenNumber[i] = '-';
            tryNumber[i] = ' ';
            bull++;
        }
    }

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++) {
            if (hiddenNumber[i] == tryNumber[j]) {
                hiddenNumber[i] = '-';
                tryNumber[j] = ' ';
                cow++;
                break;
            }
        }
    } 

    std::cout << "Быков: " << bull << ", "
              << "коров: " << cow << "\n";

    return 0;
}
