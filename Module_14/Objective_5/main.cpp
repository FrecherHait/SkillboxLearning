#include <iostream>
#include <limits>

void clearInputBuffer(){
    if (std::cin.fail() || std::cin.peek() != '\n'){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

bool checkCorrectPos(std::pair<int, int> pos) {
    if (pos.first - 1 >= 0 && pos.first - 1 < 12 && pos.second - 1 >= 0 && pos.second - 1 < 12) {
        return true;
    }

    std::cout << "Incorrect position value, try again!" << "\n";
    return false;
}

template<int x, int y>
void initPops(bool (&popsChecker)[x][y], char (&popsPackage)[x][y]){
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            popsChecker[i][j] = true;
            popsPackage[i][j] = 'o';
        }
    }
}

template<int x, int y>
void printBubblePackage(char (&popsPackage)[x][y]) {
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            std::cout << popsPackage[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<int x, int y>
void popBubbles(bool (&popsChecker)[x][y], char (&popsPackage)[x][y]){
    int counterBubbles = x * y;

    std::cout << "Current package: " << std::endl;
    printBubblePackage(popsPackage);

    while (counterBubbles) {
        std::pair<int, int> beginPos, endPos;

        std::cout << "Print begin position(x, y): ";
        std::cin >> beginPos.first >> beginPos.second;

        clearInputBuffer();

        if (!checkCorrectPos(beginPos)) {
            continue;
        }

        std::cout << "Print end position(x, y): ";
        std::cin >> endPos.first >> endPos.second;

        clearInputBuffer();

        if (!checkCorrectPos(endPos)) {
            continue;
        }

        auto [minPosX, maxPosX] = std::pair<int, int> {std::min(beginPos.first, endPos.first),
                                                                 std::max(beginPos.first, endPos.first)};

        auto [minPosY, maxPosY] = std::pair<int, int> {std::min(beginPos.second, endPos.second),
                                                         std::max(beginPos.second, endPos.second)};

        for (int i = minPosX; i <= maxPosX; i++) {
            for (int j = minPosY; j <= maxPosY; j++) {
                if (popsChecker[j - 1][i - 1]) {
                    std::cout << "POP!" << "\n";
                    popsChecker[j - 1][i - 1] = false;
                    popsPackage[j - 1][i - 1] = 'x';
                    counterBubbles--;
                }
            }
        }

        std::cout << "Current package: " << std::endl;
        printBubblePackage(popsPackage);
        }
}

int main() {
#ifdef WIN32
    system("chcp 65001");
#endif
    std::cout << "=========Модуль 14 \"Двумерные массивы и алгоритмы над ними\"=========" << std::endl;
    std::cout << "====================Задание 5 \"Пупырка\"====================" << std::endl;

    bool popsChecker[12][12];
    char popsPackage[12][12];

    initPops(popsChecker, popsPackage);
    popBubbles(popsChecker, popsPackage);

    return 0;
}