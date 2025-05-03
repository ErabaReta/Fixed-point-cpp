#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	
	{/* well, I made this for fast testing, I ll more later (may be)*/
		Fixed a(10);
		Fixed b(1.5f);

		std::cout << "===== testing arithmetics =======\n"
				<< a + b << '\n'
				<< a - b << '\n'
				<< a * b << '\n'
				<< a / b << '\n';
		std::cout << "===== testing incrementing ======\n"
				<< a << '\n'
				<< a++ << '\n'
				<< a << '\n'
				<< ++a << '\n'
				<< a << '\n';
		std::cout << "===== testing decrementing ======\n"
				<< a << '\n'
				<< a-- << '\n'
				<< a << '\n'
				<< --a << '\n'
				<< a << '\n';
		std::cout << "===== testing comparison ========\n"
				<< (a < b) << '\n'
				<< (a > b) << '\n'
				<< (a <= b) << '\n'
				<< (a >= b) << '\n'
				<< (a == b) << '\n'
				<< (a != b) << '\n';
		std::cout << "===== testing max/min ===========\n"
				<< Fixed::max(a, b) << '\n'
				<< Fixed::min(a, b) << '\n';
		std::cout << "==================================" << std::endl;
	}

	return 0;
}