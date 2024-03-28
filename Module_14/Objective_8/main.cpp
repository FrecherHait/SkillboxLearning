#include <iostream>

struct Field{
    bool isShipExist = false;
    bool isShipDestroyed = false;
    bool isMissShooting = false;
};

Field field_1[10][10] = {};
Field field_2[10][10] = {};

std::string checkPos(Field &m_fieldBay){
    if (m_fieldBay.isShipExist)
	return "S ";
    else
	return "• ";
}

void printFields(){
    for(int x = 0; x < 10; x++){
        std::string storeField_1 = "";
        std::string storeField_2 = "";

        for(int y = 0; y < 10; y++){
	    storeField_1 += checkPos(field_1[x][y]);
	    storeField_2 += checkPos(field_2[x][y]);
        }
	std::cout << storeField_1 + "  " + storeField_2 << std::endl;
    }
}

int main() {
#ifdef WIN32
    system("chcp 65001");
#endif
    std::cout << "=========Модуль 14 \"Двумерные массивы и алгоритмы над ними\"=========" << std::endl;
    std::cout << "====================Задание 8 \"Морской бой\"====================" << std::endl;

    printFields();

    return 0;
}