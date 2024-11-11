#include <iostream>

std::pair<int, int> getValuesFromSum(int numbers[], int size, int result){
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

    return values;
}

int main(){
    int numbers[4] = {2, 7, 11, 15};
    int sizeNumberStorage = sizeof(numbers) / sizeof(*numbers);

    auto [numFirst, numLast] = getValuesFromSum(numbers, sizeNumberStorage, 9);
    std::cout << "Result: " << numFirst << " " << numLast << std::endl;

    return 0;
}
