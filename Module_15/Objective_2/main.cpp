#include <iostream>

int main(){
    int numbers[4] = {2, 7, 11, 15};
    int result = 26;

    std::pair<int, int> values;

    for (int i = 0; i < 4; i++){
	for (int j = 1 + i; j < 4; j++){
	    int sum = numbers[i] + numbers[j];
	    if (sum == result){
		values = std::make_pair(numbers[i], numbers[j]);
		break;
	    }
	}
    }

    std::cout << "Result: " << values.first << " " << values.second << std::endl;

    return 0;
}