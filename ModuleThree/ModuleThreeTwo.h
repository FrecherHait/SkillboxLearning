#pragma once
#include <iostream>
class ModuleThreeTwo
{
public:
	ModuleThreeTwo();
	~ModuleThreeTwo();

	void run();
private:
	int a;
	int b;
	int buffer; // Нужна для хранения копии одной из переменных, чтобы все было корректно
};

