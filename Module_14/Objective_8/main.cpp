#include <iostream>
#include <map>
#include <set>

enum class FieldCellState{
    EMPTY,
    SHIP,
    SHIP_DESTROYED,
    MISSING_SHOOT
};

const std::map<FieldCellState, std::string> iconsStateCell= {
    { FieldCellState::EMPTY, "•" },
    { FieldCellState::SHIP, "🛥" },
    { FieldCellState::SHIP_DESTROYED, "💥" },
    { FieldCellState::MISSING_SHOOT, "❌" }
};

FieldCellState field_1[10][10] = {};
FieldCellState field_2[10][10] = {};

void printFields(){
    for(int x = 0; x < 10; x++){
        std::string storeField_1 = "";
        std::string storeField_2 = "";

        for(int y = 0; y < 10; y++){
          storeField_1 += (iconsStateCell.at(field_1[x][y]) + " ");
          storeField_2 += (iconsStateCell.at(field_2[x][y]) + " ");
        }

	      std::cout << storeField_1 + "  " + storeField_2 << std::endl;
    }
}

bool checkCorrectPosition(std::pair<int, int> pos){
    auto [x, y] = pos;

    if (x < 1 && x > 10 && y < 1 && y > 10){
        std::cout << "Error placement ship or shoot in current position. Out of field." << std::endl;
        return false;
    }
    
    return true;
}

bool buildShip(FieldCellState field[10][10], int pos1[2], int pos2[2]){
    std::string errorMsg = "Error placement ship in range positions. Ship can placement only vertical or horizontal not diagonal.\
                            Or ship is already exist in current position.";

    if (pos1[0] == pos2[0] || pos1[1] == pos2[1]){
        for (int i = pos1[0] - 1; i < pos2[0]; i++){
            for (int j = pos1[1] - 1; j < pos2[1]; j++){
                if (field[j][i] == FieldCellState::EMPTY){
                    field[j][i] = FieldCellState::SHIP;
                }
                else {
                    std::cout << errorMsg << std::endl;
                    return false;
                }
            }
        }
        return true;
    }

    std::cout << errorMsg << std::endl;
    return false;
}

bool buildShip(FieldCellState field[10][10], const std::pair<int, int> pos){
    auto [x, y] = pos;

    if (field[y-1][x-1] == FieldCellState::EMPTY){
        field[y-1][x-1] = FieldCellState::SHIP;
        return true;
    }

    std::cout << "Error placement ship in current position. Ship is already exist or out of field." << std::endl;
    return false;
}

void buildShips() {
    bool finishBuild = false;
    int sizeShip = 1;

    enum class PlayerQueue{ FIRST = 1, SECOND };

    PlayerQueue playerQueue = PlayerQueue::FIRST;

    while (!finishBuild){
        bool successBuild = false;

        if (sizeShip == 1){
            int x, y;

            std::cout << "Player " << (int)playerQueue << ", placement ship size " << sizeShip << " on pos(x, y): ";
            std::cin >> x >> y;

            successBuild = checkCorrectPosition(std::make_pair(x, y)) && 
                           buildShip(playerQueue == PlayerQueue::FIRST ? field_1 : field_2, std::make_pair(x, y));
        }
        else {
            int x1, x2, y1, y2;

            std::cout << "Player " << (int)playerQueue << ", placement ship size " << sizeShip << " on start pos(x, y): ";
            std::cin >> x1 >> y1;

            std::cout << "Player " << (int)playerQueue << ", placement ship size " << sizeShip << " on end pos(x, y): ";
            std::cin >> x2 >> y2;

            if (x1 == x2 - (sizeShip - 1) || y1 == y2 - (sizeShip - 1)){ // дописать условие
                int pos1[2] = { x1, y1 };
                int pos2[2] = { x2, y2 };

                successBuild = checkCorrectPosition(std::make_pair(x1, y1)) && 
                               checkCorrectPosition(std::make_pair(x2, y2)) && 
                               buildShip(playerQueue == PlayerQueue::FIRST ? field_1 : field_2, pos1, pos2);
            }
            else {
                std::cout << "Error placement ship. You input no identity value on size ship." << std::endl;
            }
        }

        if (!successBuild){
            continue; 
        }
        else if(sizeShip == 4 && playerQueue == PlayerQueue::SECOND){
            finishBuild = true;
        }
        else if (playerQueue == PlayerQueue::SECOND){
            sizeShip++;
        }

        printFields();
        playerQueue = playerQueue == PlayerQueue::FIRST ? PlayerQueue::SECOND : PlayerQueue::FIRST;
    }
}

bool shoot(FieldCellState field[10][10], std::pair<int, int> pos){
    auto [x, y] = pos;

    if (field[y - 1][x - 1] == FieldCellState::SHIP){
        field[y - 1][x - 1] = FieldCellState::SHIP_DESTROYED;
        return true;
    }

    field[y - 1][x - 1] = FieldCellState::MISSING_SHOOT;
    return false;
}

void startGame(){
    int player1_HP = 20;
    int player2_HP = 20;

    enum class PlayerQueue{ FIRST = 1, SECOND };
    PlayerQueue playerQueue = PlayerQueue::FIRST;
    
    std::cout << "Game started" << std::endl << std::endl;

    while(player1_HP && player2_HP){
        int x, y;
        std::cout << "Player " << (int)playerQueue << ", input shoot position (x, y): ";
        std::cin >> x >> y;

        if (!checkCorrectPosition(std::make_pair(x, y)))
            continue;

        bool successShoot = shoot(playerQueue == PlayerQueue::FIRST ? field_2 : field_1, std::make_pair(x, y));

        if (successShoot){
            if (playerQueue == PlayerQueue::FIRST){
                player2_HP--;
            }
            else {
                player1_HP--;
            }
        }

        playerQueue = playerQueue == PlayerQueue::FIRST ? PlayerQueue::SECOND : PlayerQueue::FIRST;
        printFields();
    }

    std::cout << "End game! Player " << (player1_HP ? "1" : "2") << "win!";
}

int main() {
#ifdef WIN32
    system("chcp 65001");
#endif
    std::cout << "=========Модуль 14 \"Двумерные массивы и алгоритмы над ними\"=========" << std::endl;
    std::cout << "====================Задание 8 \"Морской бой\"====================" << std::endl;

    printFields();
    buildShips();
    startGame();
    //std::cout << "\U0001F600"<< std::endl;

    return 0;
}