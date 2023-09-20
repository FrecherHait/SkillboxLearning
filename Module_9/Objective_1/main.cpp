#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // Для вывода русских символов в консоль Visual Studio
    setlocale(LC_ALL, "ru_RU.utf8");

    std::cout << "----Практическое задание для модуля 9 \"Строки и текстовые данные. Базовые алгоритмы со строками\"----"
              << "\n";
    std::cout << "---------------------Задание 1 \"Время в пути\"---------------------" << "\n";

    auto checkValue = [&](const std::istringstream &checker ) {
        if (checker.fail()) {
            std::cout << "Ошибка записи времени! Введено некорректное время." << "\n";
            exit (-1);
        }
        else if (checker.str().length() != 5) {
            std::cout << "Ошибка записи времени! Введено не 5 символов" << "\n";
            exit (-2);
        }
    };
    struct tm storeTimeIn{}, storeTimeOut{};

    std::istringstream checkerTime;

    std::string timeOut;
    std::cout << "Введите время отправления: ";
    std::cin >> timeOut;

    checkerTime.str(timeOut);
    checkerTime >> std::get_time(&storeTimeOut, "%H:%M");
    checkValue(checkerTime);

    std::string timeIn;
    std::cout << "Введите время прибытия: ";
    std::cin >> timeIn;

    checkerTime.clear();
    checkerTime.str(timeIn);
    checkerTime >> std::get_time(&storeTimeIn, "%H:%M");
    checkValue(checkerTime);

    std::pair<int, int>resultTime;

    if (storeTimeOut.tm_hour == storeTimeIn.tm_hour && storeTimeOut.tm_min > storeTimeIn.tm_min)
        resultTime.first = 23;
    else if (storeTimeOut.tm_hour > storeTimeIn.tm_hour)
        resultTime.first = 24 - std::abs(storeTimeOut.tm_hour - storeTimeIn.tm_hour);
    else
        resultTime.first = storeTimeIn.tm_hour - storeTimeOut.tm_hour;

    if (storeTimeOut.tm_min > storeTimeIn.tm_min) {
        resultTime.second = 60 - std::abs(storeTimeOut.tm_min - storeTimeIn.tm_min);
        if (storeTimeOut.tm_hour > storeTimeIn.tm_hour) {
            resultTime.first--;
        }
    }
    else if (storeTimeOut.tm_min == storeTimeIn.tm_min)
        resultTime.second = 0;
    else
        resultTime.second = storeTimeIn.tm_min - storeTimeOut.tm_min;

    std::cout << "Поездка составила " << resultTime.first << " ч. "
              << resultTime.second << " мин." << "\n";

    return 0;
}
