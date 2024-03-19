#include <iostream>

template<int a, int b>
void fillMatrix(int (&matrix)[a][b]){
    int number = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = number;
            number++;
        }
    }

}

template<int a, int b>
void printSnakeMatrix(int (&matrix)[a][b]) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            std::cout << matrix[i][j + (b - 1 - 2 * j) * (i % 2)] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
#ifdef WIN32
    system("chcp 65001");
#endif
    std::cout << "=========Модуль 14 \"Двумерные массивы и алгоритмы над ними\"=========" << std::endl;
    std::cout << "====================Задание 6 \"Проход змейкой\"====================" << std::endl;

    int matrix[5][5];
    fillMatrix(matrix);
    printSnakeMatrix(matrix);

    return 0;
}