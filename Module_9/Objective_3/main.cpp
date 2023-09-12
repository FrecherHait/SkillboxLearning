#include <iostream>
#include <cmath>

int main() {
    // Для вывода русских символов в консоль Visual Studio
    setlocale(LC_ALL, "ru_RU.utf8");

    std::cout << "----Практическое задание для модуля 9 \"Строки и текстовые данные. Базовые алгоритмы со строками\"----"
              << "\n";
    std::cout << "---------------------Задание 3 \"Подсчёт количества слов\"---------------------" << "\n";

    std::string lines;
    std::cout << "Введите строку:" << "\n";
    std::getline(std::cin, lines);

    int countSymbol = 0;
    bool symbolExist = false;

    for (char line : lines) {
        if (line == ' ') {
            symbolExist = false;
            continue;
        }
        else if (symbolExist)
            continue;

        symbolExist = true;
        countSymbol++;
    }

    std::cout << "Ответ: " << countSymbol << "\n";

    return 0;
}
