#include <iostream>

void checkValidData(std::string line, std::pair<int, int> &countSymbolsOnField) {
    if ((int) line.length() != 3) {
        std::cout << "Incorrect" << "\n";
        exit(-1);
    }
    else 
        for (auto currentPos : line) {
            switch(currentPos) {
                case 'X':
		    countSymbolsOnField.first++;
                    break;
                case 'O':
		    countSymbolsOnField.second++;
                    break;
                case '.':
                    break;
                default:
                    std::cout << "Incorrect" << "\n";
                    exit(-1);
            }
        }
}

char checkWinner(std::string lines) {
    char playingField [3][3];

    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            playingField[row][col] = lines[(row * 3) + col];

    int i;

    for(i=0; i<3; i++)  
        if(playingField[i][0] == playingField[i][1] &&
            playingField[i][0] == playingField[i][2]) return playingField[i][0] != '.' ? playingField[i][0] : ' ';

    for(i=0; i<3; i++)  
        if(playingField[0][i] == playingField[1][i] &&
            playingField[0][i] == playingField[2][i]) return playingField[0][i] != '.' ? playingField[0][i] : ' ';

    if(playingField[0][0] == playingField[1][1] &&
        playingField[1][1] == playingField[2][2])
        return playingField[0][0] != '.' ? playingField[0][0] : ' ';

    if(playingField[0][2] == playingField[1][1] &&
        playingField[1][1] == playingField[2][0])
        return playingField[0][2] != '.' ? playingField[0][2] : ' ';
    
    return ' ';
}

bool checkCorrectFillField(const char symbol, const std::pair<int, int> &countSymbolsOnField) {
    if (countSymbolsOnField.first > 5 || countSymbolsOnField.second > 4)
        return false;

    switch (symbol)
    {
    case 'X':
        if (countSymbolsOnField.first == countSymbolsOnField.second + 1) {
            std::cout << "Petya won." << "\n";
            return true;
        }

        return false;
    case 'O':
        if (countSymbolsOnField.first == countSymbolsOnField.second) {
            std::cout << "Vanya won." << "\n";
            return true;
        }
        return false;
    default:
        std::cout << "Nobody" << "\n";
        return true;

    return false;
    }
}

int main() {
    std::cout << "----Практическое задание для модуля 11 \"Функции в программировании\"----" << "\n";
    std::cout << "-----------------Задание 4 \"Оценка результатов игры в крестики-нолики\"-----------------" << "\n";

    std::cout << "Введите результат игры(3x3): " << "\n";

    std::string lineUp;
    std::string lineMiddle;
    std::string lineDown;

    std::cin >> lineUp;
    std::cin >> lineMiddle;
    std::cin >> lineDown;

    std::pair<int, int> counterSymbolsOnField;

    checkValidData(lineUp, counterSymbolsOnField);
    checkValidData(lineMiddle, counterSymbolsOnField);
    checkValidData(lineDown, counterSymbolsOnField);

    if (!checkCorrectFillField(checkWinner(lineUp + lineMiddle + lineDown), counterSymbolsOnField))
        std::cout << "Incorrect." << "\n";

    return 0;
}
