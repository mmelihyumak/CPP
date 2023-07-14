#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int fixedPointValue;
		const static int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float floatingPoint);
		~Fixed();
		Fixed(const Fixed &fixed);
		void operator=(const Fixed &fixed);
		int getRawBits(void) const; //that returns the raw value of the fixed point value.
		void setRawBits(const int raw); //that sets the raw value of the fixed point value.
		float toFloat(void) const;
		int toInt(void) const;
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		static const Fixed& min(const Fixed &fixed1, const Fixed &fixed2);
		static const Fixed& max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream &operator<<(std::ostream& os, const Fixed &fixed);

#endif