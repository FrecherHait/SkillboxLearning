#include <iostream>
#include <vector>

bool checkFirstPartEmail(const char &symbol, int &size) {
    std::string symbols = "!#$%&'*+-/=?^_`{|}~";

    if (size > 64)
        return false;
    else
        for (auto curSymbol : symbols) {
            if (curSymbol == symbol)
                return true;
        }

    return isdigit(symbol) || isalpha(symbol);
}

bool checkSecondPartEmail(const char &symbol, int &size) {
    return symbol != '@' && (symbol == '-' || isdigit(symbol) || isalpha(symbol)) && size <= 63;
}

int main() {
    std::cout << "----Практическое задание для модуля 11 \"Функции в программировании\"----" << "\n";
    std::cout << "---------Задание 2 \"Проверка корректности email-адреса\"---------" << "\n";
    
    std::string email;
    std::cout << "Введите e-mail: ";
    std::cin >> email;

    bool validEmail = false;

    int firstPartCount = 0;
    int secondPartCount = 0;

    if (email[0] != '.' || email[email.length() - 1] != '.') {
        bool usePoint = true;
        bool firstPartDone = false;

        validEmail = true;

        for (auto curSymbol : email) {
            if (curSymbol == '.' && usePoint) {
                usePoint = false;
                continue;
            }
            else if (curSymbol == '@' && !firstPartDone) {
                usePoint = false;
                firstPartDone = true;
                continue;
            }
            else {
                if (validEmail = firstPartDone ? checkSecondPartEmail(curSymbol, ++secondPartCount) : checkFirstPartEmail(curSymbol, ++firstPartCount)) {
                    usePoint = true;
                    continue;
                }
                break;
            }
        }
    }

    validEmail && firstPartCount && secondPartCount ? std::cout << "Yes" << "\n" : 
                                                      std::cout << "No" << "\n";
    return 0;
}