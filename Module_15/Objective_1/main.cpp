#include <locale>
#include <iostream>

int main(){
    //std::locale ru("ru_RU.UTF8");
    int numbers[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    std::pair<int, int> indexes;

    int result = 0;

    for (int i = 0; i < 9; i++){
	int temp = 0;
	for (int j = 0; j < 9 - i; j++){
	    temp += numbers[i+j];
	    if (temp > result){
		result = temp;
		indexes = std::make_pair(i, i+j);
	    }
	}
    }

    std::cout << "indexes(" << indexes.first << "," << indexes.second << ")" << std::endl; 

    return 0;
}