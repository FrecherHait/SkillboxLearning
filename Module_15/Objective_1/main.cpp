#include <iostream>

std::pair<int, int> getResultIndexes(int numbers[], const int size){
    std::pair<int, int> indexes;

    int maxSum = 0;

    for (int i = 0; i < size; i++){
        for (int currentSum = 0, j = 0; j < size - i; j++){
            currentSum += numbers[i+j];
            if (currentSum > maxSum){
                maxSum = currentSum;
                indexes = std::make_pair(i, i+j);
            }
        }
    }

    return indexes;
}

int main(){
    int numbers[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int sizeNumberStorage = sizeof(numbers) / sizeof(*numbers);

    auto [indexFirst, indexLast] = getResultIndexes(numbers, sizeNumberStorage);
    std::cout << "Result indexes(" << indexFirst<< "," << indexLast << ")" << std::endl;

    return 0;
}
