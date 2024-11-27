/*
Задача 3
Что нужно сделать

С клавиатуры вводятся числа. Когда пользователь вводит «−1», необходимо выводить на экран пятое по возрастанию число среди введённых. Когда пользователь вводит «−2», программа завершает работу.
Пример

Ввод: 7 5 3 1 2 4 6 −1

Вывод: 5 (в отсортированном виде введённые числа выглядят так: {1, 2, 3, 4, 5, 6, 7})

Ввод: 1 1 1 −1

Вывод: 2 (в отсортированном виде введённые числа выглядят так: {1, 1, 1, 1, 2, 3, 4, 5, 6, 7})

Ввод: −2

Завершение программы

Важная часть задания — оптимальное использование ресурсов. Для решения этой задачи достаточно хранить в векторе только пять наименьших элементов.

Например, если мы храним массив [1,3,5,7,9] и вводим число 15 — его можно отбросить, так как оно уже никогда не будет пятым в ряду введённых чисел. А если вводится число 8, массив должен поменяться на [1,3,5,7,8], и теперь всё, что больше 8, можно игнорировать.
Рекомендация

Удостоверьтесь, что требуемое число можно вывести (может быть меньше пяти чисел).
 */

#include <iostream>
#include <vector>

bool sorted = false;

void sortValues(std::vector<int> &values){
    for (int size = 0; size < 5; size++){
        auto [index, minValue] = std::make_pair(size, values[size]);

        for(int i = 1 + size; i < values.size(); i++){
            if (values[i] < minValue){
                minValue = values[i];
                index = i;
            }
        }

        std::swap(values[size], values[index]);
    }

    sorted = true;
    values.resize(5);
}

int main(){
    std::vector<int> values;

    int input;
    std::cout << "Input value: ";

    while ((std::cin >> input) && input != -2){
        if (input == -1){
            if (values.size() >= 5){
                sortValues(values);
                std::cout << "Output: " << values[4] << std::endl;
                continue;
            }
            else {
                std::cout << "Error output: size numbers not equal or upper 5" << std::endl;
                continue;
            }
        }
        values.push_back(input);
    }

    std::cout << "End program." << std::endl;
    return 0;
}
