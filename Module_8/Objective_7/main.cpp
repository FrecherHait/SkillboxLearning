#include <iostream>
#include <cmath>
#include <variant>

using DiffVal = std::variant<int, float>;

int main() {

    // Для вывода русских символов в консоль Visual Studio
    setlocale(LC_ALL, "ru_RU.utf8");

    std::cout << "----Практическое задание для модуля 8 \"Числа с плавающей запятой. Математические вычисления\"----"
              << "\n";
    std::cout << "---------------------Задание 7 \"Друзья Оушена\"---------------------" << "\n";

    auto checkValue = [&](const DiffVal& val) {
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cout << "Ошибка! Вы ввели не число." << "\n";
            exit(-1);
        }
        else if (auto intVal = std::get_if<int>(&val)) {
            if (*intVal <= 0) {
                std::cout << "Ошибка! Вы ввели некорретное число." << "\n";
                exit(-2);
            }
        }
        else if (auto floatVal = std::get_if<float>(&val)) {
            if (*floatVal <= 0.f) {
                std::cout << "Ошибка! Вы ввели некорретное число." << "\n";
                exit(-2);
            }
        }
    };

    int N;
    std::cout << "Введите количество крутящихся ручек: ";
    std::cin >> N;

    checkValue(N);

    int K;
    std::cout << "Введите количество положений: ";
    std::cin >> K;

    checkValue(K);

    float T;
    std::cout << "Введите среднее время на проверку одной комбинации: ";
    std::cin >> T;

    checkValue(T);

    float finallyTimeOfSearchCombinations = std::pow((float)K, (float)N) * T;
    std::cout << "Время которое требуется для перебора всех комбинаций составляет " << finallyTimeOfSearchCombinations << " секунд.";

    return 0;
}