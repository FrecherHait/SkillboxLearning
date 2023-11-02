#include <iostream>
#include <vector>

float calculatePrice(std::vector<float> &prices, std::vector<int> &items) {
    float result = 0.f;
    for (int i = 0; i < items.size(); i++) {
        int index = items[i];

        if (index > prices.size() - 1 || index < 0) {
            std::cout << "Error! Out of range." << "\n";
            exit(-1);
        }

        result += prices[index];
    }

    return result;
}

int main() {
    std::cout << "----Практическое задание для модуля 13 \"Знакомство с std::vector v2\"----" << "\n";
    std::cout << "---------------------Задание 2---------------------" << "\n";

    std::vector<float> prices {2.5, 4.5, 3.0, 10.0, 42.0};
    std::vector<int> items {1, 1, 4, 3, 4};

    std::cout << "Total price: " << calculatePrice(prices, items) << "\n";

    return 0;
}