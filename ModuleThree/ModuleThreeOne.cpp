#include "ModuleThreeOne.h"
#include <iostream>
ModuleThreeOne::ModuleThreeOne() {
	setlocale(LC_ALL, "rus");

	totalPassengers = 0;
	totalMoney      = 0;
	inPassengers    = 0;
	outPassengers   = 0;
	salaryDriver    = 0;
	fuel            = 0;
	taxes           = 0;
	repair          = 0;
	profit          = 0;
	stop            = "";
}

void ModuleThreeOne::run() {

	stop = "����� �������������";

	std::cout << "��������� �� ��������� \"" << stop << "\". � ������ ����������: " << totalPassengers << "\n";
	std::cout << "������� ���������� �������� ����������: ";
	std::cin  >> inPassengers;

	std::cout << "������� ���������� �������� ����������: ";
	std::cin  >> outPassengers;

	totalPassengers += inPassengers;
	totalPassengers -= outPassengers;
	totalMoney      += inPassengers * 20;

	std::cout << "������� ���������� �����? " << outPassengers << "\n";
	std::cout << "������� ���������� ����� �� ���������? " << inPassengers << "\n";
	std::cout << "������������ � ��������� \"" << stop << "\". � ������ ����������: " << totalPassengers << "\n";
	std::cout << "-----------����---------\n\n";

	stop = "�������� ����������";

	std::cout << "��������� �� ��������� \"" << stop << "\". � ������ ����������: " << totalPassengers << "\n";
	std::cout << "������� ���������� �������� ����������: ";
	std::cin  >> inPassengers;

	std::cout << "������� ���������� �������� ����������: ";
	std::cin  >> outPassengers;

	totalPassengers += inPassengers;
	totalPassengers -= outPassengers;
	totalMoney      += inPassengers * 20;

	std::cout << "������� ���������� �����? " << outPassengers << "\n";
	std::cout << "������� ���������� ����� �� ���������? " << inPassengers << "\n";
	std::cout << "������������ � ��������� \"" << stop << "\". � ������ ����������: " << totalPassengers << "\n";
	std::cout << "-----------����---------\n\n";

	stop = "����������� ����";

	std::cout << "��������� �� ��������� \"" << stop << "\". � ������ ����������: " << totalPassengers << "\n";
	std::cout << "������� ���������� �������� ����������: ";
	std::cin  >> inPassengers;

	std::cout << "������� ���������� �������� ����������: ";
	std::cin  >> outPassengers;

	totalPassengers += inPassengers;
	totalPassengers -= outPassengers;
	totalMoney      += inPassengers * 20;

	std::cout << "������� ���������� �����? " << outPassengers << "\n";
	std::cout << "������� ���������� ����� �� ���������? " << inPassengers << "\n";
	std::cout << "������������ � ��������� \"" << stop << "\". � ������ ����������: " << totalPassengers << "\n";
	std::cout << "-----------����---------\n\n";

	stop = "�������� ���";

	std::cout << "��������� �� �������� ��������� \"" << stop << "\". � ������ ����������: " << totalPassengers << "\n";

	//����� � �������� �� ��������������� ����� ���� ���������� �� �������� ���������
	inPassengers     = 0;
	outPassengers    = totalPassengers;
	totalPassengers -= totalPassengers;

	std::cout << "������� ���������� �����? " << outPassengers << "\n";
	std::cout << "������� ���������� ����� �� ���������? " << inPassengers << "\n";
	std::cout << "� ������ ���������� : " << totalPassengers << "\n";
	std::cout << "-----------��������---------\n\n";

	salaryDriver = totalMoney / 4;
	fuel         = totalMoney / 5;
	taxes        = totalMoney / 5;
	repair       = totalMoney / 5;
	profit       = totalMoney - (salaryDriver + fuel + taxes + repair);

	std::cout << "����� ����������: "         << totalMoney << "\n";
	std::cout << "�������� ��������: "        << salaryDriver << "\n";
	std::cout << "������� �� �������: "       << fuel << "\n";
	std::cout << "������: "                   << taxes << "\n";
	std::cout << "������� �� ������ ������: " << repair << "\n";
	std::cout << "����� �����: "              << profit << "\n";
}

ModuleThreeOne::~ModuleThreeOne() {

}