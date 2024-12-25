#include <iostream>
#include <vector>

void sortValues(std::vector<int> &values){
    for (int size = 0; size < 5; size++){
        auto [index, minValue] = std::make_pair(size, values[size]);

        for(int i = 1 + size; i < values.size(); i++){
            if (values[i] < minValue){
                minValue = values[i];
                index = i;
            }
        }

        std::swap(values[size], values[index]);
    }

    values.resize(5);
}

int main(){
    std::vector<int> values;

    int input;
    std::cout << "Input value: ";

    while ((std::cin >> input) && input != -2){
        if (input == -1){
            if (values.size() >= 5){
                sortValues(values);
                std::cout << "Output: " << values[4] << std::endl;
                continue;
            }
            else {
                std::cout << "Error output: size numbers not equal or upper 5" << std::endl;
                continue;
            }
        }
        values.push_back(input);
    }

    std::cout << "End program." << std::endl;
    return 0;
}
