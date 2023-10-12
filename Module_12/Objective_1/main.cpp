#include <iostream>
#include <string>
#include <limits>

void checkValue(int value) {
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cout << "Error! Incorrect input value." << "\n";
        exit(-1);
    }
    else if (value > 10) {
        std::cout << "Error! Value more than 10" << "\n";
        exit(-2);
    }
}

int main() {
    std::cout << "----Практическое задание для модуля 12 \"Одномерные массивы. Базовые алгоритмы на массивах\"----" << "\n";
    std::cout << "---------------------Задание 1 \"Многоквартирный дом\"---------------------" << "\n";   

    std::string names[10];
    
    for (int i = 0; i < 10; i++) {
        std::cout << "Input " << i+1 << " name: ";
        std::cin >> names[i];
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < 3; i++) {
        int floor;
        std::cout << "Input floor: ";
        std::cin >> floor;

        checkValue(floor);

        std::cout << "In floor " << floor << " live " << names[floor-1] << "\n";
    }

    return 0;
}