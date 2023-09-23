#include <iostream>
#include <cmath>
int main()
{
    std::cout << "----Практическое задание для модуля 10 \"Установка и настройка IDE\"----" << "\n";
    std::cout << "---------------------Задание \"Решение квадратного уравнения\"---------------------" << "\n";

    int a, b, c;
    std::cout << "Enter a, b, c: ";
    std::cin >> a >> b >> c;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cout << "Error! Not a quadratic equation!" << std::endl;
    }
    else if (a == 0)
        std::cout << "Error! \"a\" cannot be equal to 0";
    else
    {
        float discriminant = std::pow((float) b, 2.f) - 4.f * (float) a * (float) c;
        if (discriminant > 1)
        {
            float x1 = ((float) -b + std::sqrt(discriminant)) / float(2 * a);
            float x2 = ((float)-b - std::sqrt(discriminant)) / float(2 * a);
            std::cout  << "x1 = " << x1 << std::endl
                << "x2 = " << x2 << std::endl;
        }
        else if (discriminant == 0)
        {
            float x = (float) -b / float(2 * a);
            std::cout << "x = " << x << std::endl;
        }
        else
        {
            std::cout << "Complex scenario is not supported!" << std::endl;
        }
    }
    return 0;
}