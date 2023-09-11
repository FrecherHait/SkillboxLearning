#include "ModuleThreeFour.h"
#include <iostream>

ModuleThreeFour::ModuleThreeFour() {
	a = 0;
	b = 0;
}

void ModuleThreeFour::run() {
	a = 42;
	b = 153;

	std::cout << "---Исходный вариант---\n";
	std::cout << "a: " << a << "\n"; /* На экран будет выведено 42 */
	std::cout << "b: " << b << "\n"; /* На экран будет выведено 153 */

	std::swap(a, b);

	std::cout << "---После изменений---\n";
	std::cout << "a: " << a << "\n"; /* На экран будет выведено 153 */
	std::cout << "b: " << b << "\n"; /* На экран будет выведено 42 */
}

ModuleThreeFour::~ModuleThreeFour() {

}