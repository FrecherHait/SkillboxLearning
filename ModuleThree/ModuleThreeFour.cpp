#include "ModuleThreeFour.h"
#include <iostream>

ModuleThreeFour::ModuleThreeFour() {
	a = 0;
	b = 0;
}

void ModuleThreeFour::run() {
	a = 42;
	b = 153;

	std::cout << "---�������� �������---\n";
	std::cout << "a: " << a << "\n"; /* �� ����� ����� �������� 42 */
	std::cout << "b: " << b << "\n"; /* �� ����� ����� �������� 153 */

	std::swap(a, b);

	std::cout << "---����� ���������---\n";
	std::cout << "a: " << a << "\n"; /* �� ����� ����� �������� 153 */
	std::cout << "b: " << b << "\n"; /* �� ����� ����� �������� 42 */
}

ModuleThreeFour::~ModuleThreeFour() {

}