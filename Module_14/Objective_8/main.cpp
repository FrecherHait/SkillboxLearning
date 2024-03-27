#include <iostream>

int main() {
#ifdef WIN32
    system("chcp 65001");
#endif
    std::cout << "=========Модуль 14 \"Двумерные массивы и алгоритмы над ними\"=========" << std::endl;
    std::cout << "====================Задание 8 \"Морской бой\"====================" << std::endl;

    std::string symbol = "•";

    std::cout << symbol << std::endl;

    return 0;
}