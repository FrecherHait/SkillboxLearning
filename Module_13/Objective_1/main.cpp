#include <iostream>
#include <vector>

void fillVec(std::vector<int> &vec) {
    for (auto &currentNum : vec) {
        int newNum = 0;
        std::cout << "Input number: ";
        std::cin >> newNum; 

        currentNum = newNum;
    }
}

void deleteValuesOnVec(std::vector<int> &vec) {
    int deleteNumber = 0;
    std::cout << "Input value to delete: ";
    std::cin >> deleteNumber;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == deleteNumber) {
            vec.erase(vec.begin() + i);
            --i;
        }
    }
}

void printVec(std::vector<int> &vec) {
    for (auto currentNum : vec) {
        std::cout << currentNum << " ";
    }
}

int main() {
    int sizeVec = 0;
    std::cout << "Input vector size: ";
    std::cin >> sizeVec;

    std::vector<int> vecNums(sizeVec);

    fillVec(vecNums);
    deleteValuesOnVec(vecNums);

    std::cout << "Result vector: ";
    printVec(vecNums);
    std::cout << "\n";

    return 0;
}