#pragma once

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <ostream>
# include <cmath>


class Fixed
{
	private:
		int raw_bits;// storing the bits creating the value of the fixed point (without putting the point)
		static const int fractional_bit = 8;// number of bits that represent the fraction part of the number

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
//////////////////////////////////////////////////////////////////////////////

inline Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->raw_bits = other.getRawBits();
	}
	return (*this);
}

inline int Fixed::getRawBits( void ) const
{
	return (raw_bits);
}

inline void Fixed::setRawBits( int const raw )
{
	raw_bits = raw;
}

inline Fixed::Fixed(const int integer) : raw_bits(integer * (1 << fractional_bit))
{}

inline Fixed::Fixed(const float floating_point) : raw_bits((int )roundf(floating_point * (1 << fractional_bit)))
{}

inline float Fixed::toFloat( void ) const
{
	return (((float)raw_bits / (1 << fractional_bit)));
}

inline int Fixed::toInt( void ) const
{
	return(raw_bits / (1 << fractional_bit));
}

inline std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

//=======   comparison operators =========================================

inline bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}
inline bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}
inline bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}
inline bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}
inline bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}
inline bool Fixed::operator!=(const Fixed &other) const
{
	return (!(*this == other));
}

//=======   arithmetic operators ===========================================

inline Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed new_fixed;
	new_fixed.setRawBits((this->getRawBits() + other.getRawBits()));
	return (new_fixed);
}
inline Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed new_fixed;
	new_fixed.setRawBits((this->getRawBits() - other.getRawBits()));
	return (new_fixed);
}
inline Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed new_fixed;
	new_fixed.setRawBits(((long )this->getRawBits() * other.getRawBits()) / (1 << fractional_bit));
	return (new_fixed);
}
inline Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed new_fixed;
	new_fixed.setRawBits(((long )this->getRawBits() * (1 << fractional_bit)) / other.getRawBits());
	return (new_fixed);
}

//==== increment/decrement operators ========
inline Fixed &Fixed::operator++()
{
	// this->setRawBits(this->getRawBits() + 1); // increase the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1.
	this->setRawBits(this->getRawBits() + (1 << fractional_bit));
	return (*this);
}
inline Fixed &Fixed::operator--()
{
	// this->setRawBits(this->getRawBits() + 1); // increase the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1.
	this->setRawBits(this->getRawBits() - (1 << fractional_bit));
	return (*this);
}
inline Fixed Fixed::operator++(int )
{
	Fixed tmp(*this);
	// this->setRawBits(this->getRawBits() + 1); // increase the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1.
	this->setRawBits(this->getRawBits() + (1 << fractional_bit));
	return (tmp);
}
inline Fixed Fixed::operator--(int )
{
	Fixed tmp(*this);
	// this->setRawBits(this->getRawBits() + 1); // increase the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1.
	this->setRawBits(this->getRawBits() - (1 << fractional_bit));
	return (tmp);
}
//==========================================
inline Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	return ((f1 > f2) ? f2 : f1);
}
inline const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return ((f1 > f2) ? f2 : f1);
}
inline Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	return ((f1 < f2) ? f2 : f1);
}
inline const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return ((f1 < f2) ? f2 : f1);
}

#endif