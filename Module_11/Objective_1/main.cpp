#include <iostream>
#include <cmath>

int getPosition(const char &curSymbol) {
    if (curSymbol >= 'a' && curSymbol <= 'z')
        return 'a';
    else if (curSymbol >= 'A' && curSymbol <= 'Z')
        return 'A';
    else
        return 0;
}

void encrypt_caesar(std::string &text, const int &move) {
    for (auto &curSymbol : text) {
        if (int startPos = getPosition(curSymbol)) {
            int curPos = curSymbol - startPos;
            int newPos = curPos + move;
            curSymbol = startPos + (newPos % 26);
        }
    }
}

void decrypt_caesar(std::string &text, const int &move) {
    for (auto &curSymbol : text) {
        if (int startPos = getPosition(curSymbol)) {
            int curPos = curSymbol - startPos;
            int newPos = curPos - move;
            curSymbol = startPos + (std::abs(26 + newPos) % 26);
        }
    }
}

int main() {
    std::cout << "----Практическое задание для модуля 11 \"Функции в программировании\"----" << "\n";
    std::cout << "---------------------Задание 1 \"Шифр Цезаря\"---------------------" << "\n";

    std::string text;
    std::cout << "Введите текст для шифрования: ";
    std::getline(std::cin, text);
    
    int move;
    std::cout << "Введите сдвиг шифрования: ";
    std::cin >> move;

    encrypt_caesar(text, move);
    std::cout << "Encrypt: " << text << "\n";

    decrypt_caesar(text, move);
    std::cout << "Decrypt: " << text << "\n";
    
    return 0;
}

