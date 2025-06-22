#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	
	{/* well, I made this for fast testing, I ll do more later (may be)*/
		Fixed8_t a(10);
		Fixed8_t b(1.5f);

		std::cout << "precision = " << a.getPrecision() << '\n';
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
				<< Fixed8_t::max(a, b) << '\n'
				<< Fixed8_t::min(a, b) << '\n';
		std::cout << "==================================" << std::endl;
	}
	{/* testing if casting works*/
		Fixed8_t a = static_cast<Fixed8_t>(10);
		Fixed8_t b = static_cast<Fixed8_t>(1.5f);

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
		Fixed8_t a(1);
		Fixed8_t b(0);
		try
		{
			Fixed8_t c = a / b ;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}

	return 0;
}