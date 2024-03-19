#include <iostream>

template<int ii, int jj, int kk>
void insertMatrix(int (&matrix)[ii][jj][kk]){
    std::string totalMatrix = "";
    for (int i = 0; i < ii; i++){
        for (int j = 0; j < jj; j++){
            int inputVal;
            std::cin >> inputVal;
            
            totalMatrix += inputVal + " ";

            for (int level = 0; level < inputVal; level++){
              matrix[i][j][level] = 1;
            }
        }
        totalMatrix += "\n";
    }

    std::cout << totalMatrix;
}

int main() {
#ifdef WIN32
    system("chcp 65001");
#endif
    std::cout << "=========Модуль 14 \"Двумерные массивы и алгоритмы над ними\"=========" << std::endl;
    std::cout << "====================Задание 7 \"Почти «Майнкрафт»\"====================" << std::endl;

    int matrix[5][5][10];

    std::cout << "Input matrix of heights:" << std::endl;
    insertMatrix(matrix);

    return 0;
}