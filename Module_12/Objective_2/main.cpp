#include <iostream>

void checkValue() {
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cout << "Error! Incorrect input value." << "\n";
        exit(-1);
    }
}

void heapify(float arr[], int size, int i)
{
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2;

    if (l < size && arr[l] < arr[largest])
        largest = l;

    if (r < size && arr[r] < arr[largest])
        largest = r;

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(float arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n-1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void inputArray(float arr[], int size) {
    std::cout << "Input: ";

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

void printArray(float arr[], int size) {
    std::cout << "Output: ";

    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";

    std::cout << "\n";
}

int main() {
    std::cout << "----Практическое задание для модуля 12 \"Одномерные массивы. Базовые алгоритмы на массивах\"----" << "\n";
    std::cout << "---------------------Задание 2 \"Сортировка\"---------------------" << "\n";

    float arr[15];
    int size = sizeof(arr)/sizeof(arr[0]);

    inputArray(arr, size);
    checkValue();
    heapSort(arr, size);
    printArray(arr, size);
}
