#pragma once

#ifndef __FIXED_HPP__
# define __FIXED_HPP__
# include <ostream>

class Fixed
{
	private:
		int raw_bits;// storing the bits creating the value of the fixed point (without putting the point)
		static const int fractional_bit = 8;// number of bits that represent the fraction part of the number

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int integer);
		Fixed(const float floating_point);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		//====   comparison operators ===============

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		//====   arithmetic operators ===============

		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);
		//==== increment/decrement operators ========

		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int );
		Fixed operator--(int );
		//===========================================

		static	Fixed& min(Fixed &f1, Fixed &f2);
		static	const Fixed& min(const Fixed &f1, const Fixed &f2);
		static	Fixed& max(Fixed &f1, Fixed &f2);
		static	const Fixed& max(const Fixed &f1, const Fixed &f2);


		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
	};
	std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
	
#endif