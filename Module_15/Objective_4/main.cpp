#include <iostream>
#include <vector>

void printElements(const std::string &msg, const std::vector<int> &elements){
    std::cout << msg;

    for (auto elem : elements){
        std::cout << elem << " ";
    }

    std::cout << std::endl;
}

void sortElementsByAbsolute(std::vector<int> &numbers){
    for (auto i = 0; i < numbers.size(); i++){
        for (auto j = i + 1; j < numbers.size(); j++){
            if (std::abs(numbers[j]) < std::abs(numbers[i])){
                std::swap(numbers[i], numbers[j]);
            }
        }
    }
}

int main(){
    std::vector<int> numbers = { -100, -50, -5, 1, 10, 15 };

    printElements("Elements until sort: ", numbers);
    sortElementsByAbsolute(numbers);
    printElements("Elements after sort: ", numbers);

    return 0;
}
