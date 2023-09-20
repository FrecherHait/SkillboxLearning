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

    if (std::count(floatNum.begin(), floatNum.end(), '-') > 1 || std::count(floatNum.begin(), floatNum.end(), '.') > 1) {
       std::cout << "No" << "\n";
       exit(0);
    }

    bool isValid = false;

    for (int i = 0; i < floatNum.length(); i++) {
        if (i == 0 && (isdigit(floatNum[i]) || floatNum[i] == '.' || floatNum[i] == '-'))
            continue;
        else if (isdigit(floatNum[i])) {
            isValid = true;
            continue;
        }
        else if (floatNum[i] == '.')
            continue;
 
        std::cout << "No" << "\n";
        exit(0);
    }

    if (isValid)
        std::cout << "Yes" << "\n";
    else
        std::cout << "No" << "\n";

    return 0;
}
