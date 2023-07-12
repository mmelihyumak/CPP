#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int pointValue;
		const static int fractionalBits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed);
		void operator=(const Fixed &fixed);
		const int getRawBits(void); //that returns the raw value of the fixed point value.
		void setRawBits(const int raw); //that sets the raw value of the fixed point value.
};

#endif