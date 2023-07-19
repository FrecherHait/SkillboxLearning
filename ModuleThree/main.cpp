#include <iostream>
#include "ModuleThreeOne.h"
#include "ModuleThreeTwo.h"
#include "ModuleThreeThree.h"
#include "ModuleThreeFour.h"

int main() {
	setlocale(LC_ALL, "rus");          // ��� ������ ������� �������� � ������� Visual Studio
	
	ModuleThreeOne moduleThreeOne;     // ����� ������� �������
	ModuleThreeTwo moduleThreeTwo;     // ����� ������� �������
	ModuleThreeThree moduleThreeThree; // ����� �������� �������
	ModuleThreeFour moduleThreeFour;   // ����� �������� �������

	std::cout << "----������������ ������� ��� ������ 3 \"���� ������ ������������.������\"----\n";
	
	while (true) {
		int cmdNum; // ���������� ��� ����� ������ ������
		std::cout << "\n";
		std::cout << "1 - ������� 1 \"��������� ���������\""       << "\n";
		std::cout << "2 - ������� 2 \"����� �������\""             << "\n";
		std::cout << "3 - ������� 3 \"�������� ���������\""        << "\n";
		std::cout << "4 - ������� 4 \"�������� ������ ���������\"" << "\n";
		std::cout << "0 - �����"                                   << "\n";
		std::cout << "������� ����� �������: ";
		std::cin  >> cmdNum;

		switch (cmdNum) {
		case 0:
			return 0;
		case 1:
			moduleThreeOne.run();
			break;
		case 2:
			moduleThreeTwo.run();
			break;
		case 3:
			moduleThreeThree.run();
			break;
		case 4:
			moduleThreeFour.run();
			break;
		}
	}
}