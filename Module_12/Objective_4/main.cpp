#include <iostream>

int repeatedNumber(int numbers[], int size) {
    int mask = 0; // Используем битовую маску для отслеживания элементов

    for (int i = 0; i < size; ++i) {
        int element = numbers[i];
        
        // Проверяем, был ли уже обнаружен текущий элемент
        if ((mask & (1 << element)) != 0) {
            return element;
        }
        
        // Устанавливаем бит для текущего элемента
        mask |= (1 << element);
    }

    return -1; 
}

int main() {
    std::cout << "----Практическое задание для модуля 12 \"Одномерные массивы. Базовые алгоритмы на массивах\"----" << "\n";
    std::cout << "---------------------Задание 4 \"Ряд чисел\"---------------------" << "\n";

    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int result = repeatedNumber(numbers, size);

    result > 0 ? std::cout << "Repeat num: " << result << "\n" : std::cout << "Repeat num not found" << "\n";
    return 0;
}