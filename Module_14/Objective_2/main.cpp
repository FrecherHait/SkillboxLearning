#include <iostream>

bool checkWinner(char field[][3], int currentRow) {
	int foundCnt = 0;
    for(int i = 0; i < 3; i++){
		if (field[currentRow][currentRow] == field[currentRow][i] && field[currentRow][currentRow] != ' ')
			foundCnt++;
		else if (field[currentRow][currentRow] == field[i][currentRow] && field[currentRow][currentRow] != ' ')
			foundCnt++;

		if (foundCnt == 3)
			return true;
    }

    return false;
}

void printCurrentField(char field[][3]){

    for (int i = 0; i < 3; i++){
		std::cout << "|";
		for (int j = 0; j < 3; j++)
			std::cout << field[i][j] << "|";
		std::cout << std::endl;
    }
}

int main() {
    char field[3][3] = {{' ',' ',' '},
                        {' ',' ',' '},
                        {' ',' ',' '}};

    bool places[3][3]= {{false, false, false},
                        {false, false, false},
                        {false, false, false}};

    int gameTurnCount = 9;
    char player = 'X';
    while (gameTurnCount) {
		int x, y;
		std::cout << "Input position fill field(x, y)";
		std::cin >> x >> y;

		if (x < 1 || x > 3 || y < 1 || y > 3) {
			std::cout << "Incorrect input position, please enter number 1-3 in x and y position!" << std::endl;
			continue;
		}
		else if (places[x-1][y-1]){
			std::cout << "Current position is busy! Please, choice another position." << std::endl;
			continue;
		}

		field[x-1][y-1] = player;
		places[x-1][y-1] = true;

		printCurrentField(field);

		if (checkWinner(field, x-1)){
			std::cout << "Player '" << player << "' wins!" << std::endl;
			return 0;
	}
	else if (player == 'X') player = 'O';
	else if (player == 'O') player = 'X';

	gameTurnCount--;
    }

    std::cout << "Game end! No winners." << std::endl;
}