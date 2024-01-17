#include <iostream>

void printMatrix(const float matrix[4][4]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void printVector(const float vector[4]) {
    for (int i = 0; i < 4; i++) {
         std::cout << vector[i] << " ";
    }
}

void fillMatrix(float matrix[4][4]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << "Input matrix element(" << i << "," << j << "): ";
            std::cin >> matrix[i][j];
        }
    }
}

void fillVector(float vector[4]){
    for (int i = 0; i < 4; i++) {
        std::cout << "Input vector element(" << i << "): ";
        std::cin >> vector[i];
    }
}

void productMatrixOnVector(const float matrix[4][4], const float vector[4]){
    float resultVector[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            resultVector[i] += (matrix[i][j]*vector[j]);
        }
    }

    std::cout << std::endl << std::endl;
    std::cout << "Result: ";
    printVector(resultVector);
}

int main() {
#ifdef WIN32
    system("chcp 65001");
#endif
    std::cout << "=========Модуль 14 \"Двумерные массивы и алгоритмы над ними\"=========" << std::endl;
    std::cout << "====================Задание 4 \"Умножение матрицы на вектор\"====================" << std::endl;

    float matrix[4][4];
    float vector[4];

    fillMatrix(matrix);
    fillVector(vector);

    std::cout << std::endl;
    std::cout << "matrix:" << std::endl;
    printMatrix(matrix);

    std::cout << std::endl;
    std::cout << "vector: " << std::endl;
    printVector(vector);

    productMatrixOnVector(matrix, vector);

    return 0;
}