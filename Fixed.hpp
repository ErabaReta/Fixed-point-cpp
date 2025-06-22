#pragma once

#ifndef FIXED_HPP
# define FIXED_HPP

// # include <ostream>
// # include <cmath>

template <int fractional_bit>
class Fixed
{
	private:
		int raw_bits;// storing the bits creating the value of the fixed point (without putting the point)
		// static const int fractional_bit = 8;// number of bits that represent the fraction part of the number

	public:
		Fixed() : raw_bits(0){};
		Fixed(const Fixed &other) : raw_bits(other.raw_bits){};
		Fixed(const int integer);
		Fixed(const float floating_point);
		Fixed &operator=(const Fixed &other);
		~Fixed(){};
		//====   comparison operators ===============

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		//====   arithmetic operators ===============

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		//==== increment/decrement operators ========

		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int );
		Fixed operator--(int );
		//==== casting operators ====================

		operator int() const;
		operator float() const;
		//===========================================

		static	Fixed& min(Fixed &f1, Fixed &f2);
		static	const Fixed& min(const Fixed &f1, const Fixed &f2);
		static	Fixed& max(Fixed &f1, Fixed &f2);
		static	const Fixed& max(const Fixed &f1, const Fixed &f2);


		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		int getPrecision() const;
};


typedef Fixed<8> Fixed8_t;
typedef Fixed<16> Fixed16_t;
typedef Fixed<24> Fixed24_t; 

#include "Fixed.tpp"
#endif