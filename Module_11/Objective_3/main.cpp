#include <iostream>

bool checkGroup(const char *group){
    return atoi(group) <= 255 && (group[0] - '0') > (group[1] - '0') ? true : false;
}

bool validateIP(const std::string &m_ip){
    std::string buffer = "";
    int pointCnt = 0;

    for (int idx = 0; idx < (int) m_ip.length(); idx++) {
        if (m_ip[idx] == '.' && pointCnt++ != 3) {
            if (buffer.length() && checkGroup(buffer.c_str())) {
		        buffer.clear();
		        continue;
	        }   
	    else {
	        return false;
	    }
	}
	else if (isdigit(m_ip[idx]))
	    buffer += m_ip[idx];
	else
	    return false;
    }

    return checkGroup(buffer.c_str()) && pointCnt == 3;
}

int main() {
    std::cout << "----Практическое задание для модуля 11 \"Функции в программировании\"----" << "\n";
    std::cout << "---------------------Задание 3 \"Валидация IP-адреса\"---------------------" << "\n";

    std::string ip;
    std::cout << "Введите ip: ";
    std::cin >> ip;

    if (validateIP(ip))
        std::cout << "Yes" << "\n";
    else
        std::cout << "No" << "\n";

    return 0;
}
