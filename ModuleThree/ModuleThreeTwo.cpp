#include "ModuleThreeTwo.h"

ModuleThreeTwo::ModuleThreeTwo() {
	a = 0;
	b = 0;
	buffer = 0;
}

void ModuleThreeTwo::run() {
	a = 42;
	b = 153;

	std::cout << "---Исходный вариант---\n";
	std::cout << "a: " << a << "\n"; /* На экран будет выведено 42 */
	std::cout << "b: " << b << "\n"; /* На экран будет выведено 153 */

	buffer = a;
	a = b;
	b = buffer;

	std::cout << "---После изменений---\n";
	std::cout << "a: " << a << "\n"; /* На экран будет выведено 153 */
	std::cout << "b: " << b << "\n"; /* На экран будет выведено 42 */
}

ModuleThreeTwo::~ModuleThreeTwo() {

}