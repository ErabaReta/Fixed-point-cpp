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
	{/* testing if casting works*/
		Fixed a = static_cast<Fixed>(10);
		Fixed b = static_cast<Fixed>(1.5f);

		std::cout << "===== testing casting to Fixed type ==\n"
				<< a << '\n'
				<< b << '\n';
		
		int x = static_cast<int>(a);
		float y = static_cast<float>(b);


		std::cout << "===== testing casting from Fixed type ==\n"
				<< x << '\n'
				<< y << '\n';
		std::cout << "==================================" << std::endl;
	}
	{
		std::cout << "===== testing deviding by zero exception ==\n";
		Fixed a(1);
		Fixed b(0);
		try
		{
			Fixed c = a / b ;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}

	return 0;
}