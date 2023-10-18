#include <iostream>
#include <cassert>

float travelTime(float distance, float speed) {
    assert(speed > 0);
    return distance / speed;
}

int main() {
    std::cout << "----Практическое задание для модуля 12 \"Одномерные массивы. Базовые алгоритмы на массивах\"----" << "\n";
    std::cout << "---------------------Задание 3 \"Использование assert\"---------------------" << "\n";

    std::cout << travelTime(100, -20) << "\n";
}