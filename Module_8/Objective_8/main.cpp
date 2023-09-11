#include <iostream>
#include <cmath>

int main() {

    // Для вывода русских символов в консоль Visual Studio
    setlocale(LC_ALL, "ru_RU.utf8");

    std::cout << "----Практическое задание для модуля 8 \"Числа с плавающей запятой. Математические вычисления\"----"
              << "\n";
    std::cout << "---------------------Задание 8 \"Биолаборатория 2.0\"---------------------" << "\n";

    auto checkValue = [&](int val) {
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

    int W;
    std::cout << "Введите количество капель воды: ";
    std::cin >> W;
    checkValue(W);

    int D;
    std::cout << "Введите количество капель чистого антибиотика: ";
    std::cin >> D;
    checkValue(D);

    int Nold;
    std::cout << "Введите количество коринебактерий: ";
    std::cin >> Nold;
    checkValue(Nold);

    for (int time = 0; time < 20; time++) {
        if (Nold < 0) {
            std::cout << "Все бактерии погибли\n";
            break;
        }

        float concentration = (float) D/ (float) W;

        std::cout << "Минута " << time + 1 << ". ";
        std::cout << "Концентрация антибиотика: " << concentration;
        std::cout << ", количество бактерий: " << Nold << "\n";

        Nold *= 2;
        Nold -= std::round(Nold * concentration);
        D = std::round((float) D * 0.2f);
    }

    return 0;
}
