#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( 1 );
	Fixed const c( 4.0f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	
	std::cout << "Fixed-a: " << a.getRawBits() << std::endl;
	
	std::cout << "Pre-increment a: " << a.getRawBits() << std::endl;


	return 0;
}