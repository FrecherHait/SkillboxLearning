#pragma once
#include <iostream>

class ModuleThreeOne
{
public:
	ModuleThreeOne();  // конструктор
	~ModuleThreeOne(); // деструктор

	void run();
private:
	int totalPassengers;
	int totalMoney;
	int inPassengers;
	int outPassengers;
	int salaryDriver;
	int fuel;
	int taxes;
	int repair;
	int profit;

	std::string stop;
};

