#include <iostream>

struct WorldType{
    bool worldBox[5][5][10] = {};
    int heightSize = 0;
};

void printMatrix(WorldType& world, int slice){
    int currentLevel = world.heightSize;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (world.worldBox[i][j][currentLevel - 1] && slice <= currentLevel){
                std::cout << 1 << " ";
            }
            else{
                std::cout << 0 << " ";
            }
        }
        currentLevel--;
        std::cout << "\n";
    }
}

void insertMatrix(WorldType& world){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            int inputVal;
            std::cin >> inputVal;

            if (world.heightSize < inputVal)
                world.heightSize = inputVal;

            for (int level = 0; level < inputVal; level++){
              world.worldBox[i][j][level] = true;
            }
        }
    }
}

int main() {
#ifdef WIN32
    system("chcp 65001");
#endif
    std::cout << "=========Модуль 14 \"Двумерные массивы и алгоритмы над ними\"=========" << std::endl;
    std::cout << "====================Задание 7 \"Почти «Майнкрафт»\"====================" << std::endl;

    WorldType world;

    std::cout << "Input matrix of heights:" << std::endl;
    insertMatrix(world);

    int slice;
    std::cout << "Input slice: ";
    std::cin >> slice;
    printMatrix(world, slice);

    return 0;
}