#include <iostream>
#include <vector>

void printVector(std::vector<int> &db) {
    std::cout << "Output: ";
    for (int i = 0; i < db.capacity(); i++) {
        std::cout << db[i] << " ";
    }
    std::cout << std::endl;
}

void writeVector(std::vector<int> &db) {
    int cnt = 0;
    while(true) {
        int inputNum;
        std::cout << "Input number: ";
        std::cin >> inputNum;

        if (inputNum == -1) {
            printVector(db);
            continue;
        }
        else if (cnt < 20)
            db[cnt] = inputNum;
        else {
            db.erase(db.begin());
            db.emplace_back(inputNum);
        }

        cnt++;
    }
}

int main() {
    std::cout << "----Практическое задание для модуля 13 \"Знакомство с std::vector v2\"----" << "\n";
    std::cout << "---------------------Задание 3---------------------" << "\n";

    std::vector<int> db(20);
    //writeVector(db);
    db[0] = 1;
    db[1] = 2;
    db.erase(db.begin());

    for (int i = 0; i < 20; i++) {
        std::cout << db[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}