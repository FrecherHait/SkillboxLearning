#include "ModuleThreeTwo.h"

ModuleThreeTwo::ModuleThreeTwo() {
	a = 0;
	b = 0;
	buffer = 0;
}

void ModuleThreeTwo::run() {
	a = 42;
	b = 153;

	std::cout << "---�������� �������---\n";
	std::cout << "a: " << a << "\n"; /* �� ����� ����� �������� 42 */
	std::cout << "b: " << b << "\n"; /* �� ����� ����� �������� 153 */

	buffer = a;
	a = b;
	b = buffer;

	std::cout << "---����� ���������---\n";
	std::cout << "a: " << a << "\n"; /* �� ����� ����� �������� 153 */
	std::cout << "b: " << b << "\n"; /* �� ����� ����� �������� 42 */
}

ModuleThreeTwo::~ModuleThreeTwo() {

}