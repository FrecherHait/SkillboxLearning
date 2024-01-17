#include <iostream>

void checkElementOnDiag(std::pair<int, int> storeIndexes, int matrix[4][4]){
    auto [a, b] = storeIndexes;

    if (a != b){
        matrix[a][b] = 0;
    }
}

void comparsionMatrix(int matrixA[4][4], int matrixB[4][4]) {
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << "Input A(" << i + 1 << "," << j + 1 << ") element: ";
            std::cin >> matrixA[i][j];

            std::cout << "Input B(" << i + 1 << "," << j + 1 << ") element: ";
            std::cin >> matrixB[i][j];

            if (matrixA[i][j] != matrixB[i][j]){
                std::cout << "Element not equaly!" << "\n";
                exit(0);
            }

            checkElementOnDiag({i, j}, matrixA);
        }
    }
}

void printMatrix(int matrix[4][4]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
#ifdef WIN32
    system("chcp 65001");
#endif
    std::cout << "=========Модуль 14 \"Двумерные массивы и алгоритмы над ними\"=========" << std::endl;
    std::cout << "====================Задание 3 \"Матрицы\"====================" << std::endl;

    int matrixFirst[4][4];
    int matrixSecond[4][4];

    comparsionMatrix(matrixFirst, matrixSecond);

    std::cout << "Original matrix: " << std::endl;
    printMatrix(matrixSecond);

    std::cout << std::endl << std::endl;

    std::cout << "Changed matrix: " << std::endl;
    printMatrix(matrixFirst);
    return 0;
}