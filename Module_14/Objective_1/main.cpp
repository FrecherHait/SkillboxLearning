#include <iostream>

void printArr(int arr[2][6]){
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 6; j++)
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "----Практическое задание для модуля 14 \"Двумерные массивы и алгоритмы над ними\"----" << "\n";
    std::cout << "---------------------Задание 1 \"Банкетный стол\"---------------------" << "\n";

    int tableware[2][6] = {{4, 3, 3, 3, 3, 3}, 
                           {4, 3, 3, 3, 3, 3}};
    int crockery[2][6] = {{3, 2, 2, 2, 2, 2},
                          {3, 2, 2, 2, 2, 2}};
    int chairs[2][6] = {{1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1}};

    chairs[0][4] += 1; 
    tableware[1][2] -= 1;
    tableware[1][0] -= 1;
    tableware[1][2] += 1;
    crockery[1][0] -= 1;

    std::cout << "tableware: \n";
    printArr(tableware);
    std::cout << "crockery: \n";
    printArr(crockery);
    std::cout << "chairs: \n";
    printArr(chairs);

    return 0;
}