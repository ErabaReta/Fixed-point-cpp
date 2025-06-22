#pragma once

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <ostream>
# include <cmath>

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
};
//////////////////////////////////////////////////////////////////////////////
template <int fractional_bit>
inline Fixed<fractional_bit> &Fixed<fractional_bit>::operator=(const Fixed<fractional_bit> &other)
{
	if (this != &other)
	{
		this->raw_bits = other.getRawBits();
	}
	return (*this);
}

template <int fractional_bit>
inline int Fixed<fractional_bit>::getRawBits( void ) const
{
	return (raw_bits);
}

template <int fractional_bit>
inline void Fixed<fractional_bit>::setRawBits( int const raw )
{
	raw_bits = raw;
}

template <int fractional_bit>
inline Fixed<fractional_bit>::Fixed(const int integer) : raw_bits(integer * (1 << fractional_bit))
{}

template <int fractional_bit>
inline Fixed<fractional_bit>::Fixed(const float floating_point) : raw_bits((int )roundf(floating_point * (1 << fractional_bit)))
{}

template <int fractional_bit>
inline float Fixed<fractional_bit>::toFloat( void ) const
{
	return (((float)raw_bits / (1 << fractional_bit)));
}

template <int fractional_bit>
inline int Fixed<fractional_bit>::toInt( void ) const
{
	return(raw_bits / (1 << fractional_bit));
}

template <int fractional_bit>
inline std::ostream& operator<<(std::ostream& os, const Fixed<fractional_bit> &fixed)
{
	os << fixed.toFloat();
	return (os);
}

//=======   comparison operators =========================================

template <int fractional_bit>
inline bool Fixed<fractional_bit>::operator>(const Fixed<fractional_bit> &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

template <int fractional_bit>
inline bool Fixed<fractional_bit>::operator<(const Fixed<fractional_bit> &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

template <int fractional_bit>
inline bool Fixed<fractional_bit>::operator>=(const Fixed<fractional_bit> &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

template <int fractional_bit>
inline bool Fixed<fractional_bit>::operator<=(const Fixed<fractional_bit> &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

template <int fractional_bit>
inline bool Fixed<fractional_bit>::operator==(const Fixed<fractional_bit> &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

template <int fractional_bit>
inline bool Fixed<fractional_bit>::operator!=(const Fixed<fractional_bit> &other) const
{
	return (!(*this == other));
}
//=======   arithmetic operators ===========================================

template <int fractional_bit>
inline Fixed<fractional_bit> Fixed<fractional_bit>::operator+(const Fixed<fractional_bit> &other) const
{
	Fixed<fractional_bit> new_Fixed;
	new_Fixed.setRawBits((this->getRawBits() + other.getRawBits()));
	return (new_Fixed);
}

template <int fractional_bit>
inline Fixed<fractional_bit> Fixed<fractional_bit>::operator-(const Fixed<fractional_bit> &other) const
{
	Fixed<fractional_bit> new_Fixed;
	new_Fixed.setRawBits((this->getRawBits() - other.getRawBits()));
	return (new_Fixed);
}

template <int fractional_bit>
inline Fixed<fractional_bit> Fixed<fractional_bit>::operator*(const Fixed<fractional_bit> &other) const
{
	Fixed<fractional_bit> new_Fixed;
	new_Fixed.setRawBits(((long )this->getRawBits() * other.getRawBits()) / (1 << fractional_bit));
	return (new_Fixed);
}

template <int fractional_bit>
inline Fixed<fractional_bit> Fixed<fractional_bit>::operator/(const Fixed<fractional_bit> &other) const
{
	if (other.raw_bits == 0)
		throw (std::runtime_error("Fixed<fractional_bit>: error attemting to divide by zero"));
	Fixed<fractional_bit> new_Fixed;
	new_Fixed.setRawBits(((long )this->getRawBits() * (1 << fractional_bit)) / other.getRawBits());
	return (new_Fixed);
}
//==== increment/decrement operators ========

template <int fractional_bit>
inline Fixed<fractional_bit> &Fixed<fractional_bit>::operator++()
{
	// this->setRawBits(this->getRawBits() + 1); // increase the Fixed<fractional_bit>-point value from the smallest representable ϵ such as 1 + ϵ > 1.
	this->setRawBits(this->getRawBits() + (1 << fractional_bit));
	return (*this);
}

template <int fractional_bit>
inline Fixed<fractional_bit> &Fixed<fractional_bit>::operator--()
{
	// this->setRawBits(this->getRawBits() + 1); // increase the Fixed<fractional_bit>-point value from the smallest representable ϵ such as 1 + ϵ > 1.
	this->setRawBits(this->getRawBits() - (1 << fractional_bit));
	return (*this);
}

template <int fractional_bit>
inline Fixed<fractional_bit> Fixed<fractional_bit>::operator++(int )
{
	Fixed<fractional_bit> tmp(*this);
	// this->setRawBits(this->getRawBits() + 1); // increase the Fixed<fractional_bit>-point value from the smallest representable ϵ such as 1 + ϵ > 1.
	this->setRawBits(this->getRawBits() + (1 << fractional_bit));
	return (tmp);
}

template <int fractional_bit>
inline Fixed<fractional_bit> Fixed<fractional_bit>::operator--(int )
{
	Fixed<fractional_bit> tmp(*this);
	// this->setRawBits(this->getRawBits() + 1); // increase the Fixed<fractional_bit>-point value from the smallest representable ϵ such as 1 + ϵ > 1.
	this->setRawBits(this->getRawBits() - (1 << fractional_bit));
	return (tmp);
}
//==== casting operators ====================

template <int fractional_bit>
inline Fixed<fractional_bit>::operator int() const
{
	return (toInt());
}

template <int fractional_bit>
inline Fixed<fractional_bit>::operator float() const
{
	return (toFloat());
}
//==========================================

template <int fractional_bit>
inline Fixed<fractional_bit>& Fixed<fractional_bit>::min(Fixed<fractional_bit> &f1, Fixed<fractional_bit> &f2)
{
	return ((f1 > f2) ? f2 : f1);
}

template <int fractional_bit>
inline const Fixed<fractional_bit>& Fixed<fractional_bit>::min(const Fixed<fractional_bit> &f1, const Fixed<fractional_bit> &f2)
{
	return ((f1 > f2) ? f2 : f1);
}

template <int fractional_bit>
inline Fixed<fractional_bit>& Fixed<fractional_bit>::max(Fixed<fractional_bit> &f1, Fixed<fractional_bit> &f2)
{
	return ((f1 < f2) ? f2 : f1);
}

template <int fractional_bit>
inline const Fixed<fractional_bit>& Fixed<fractional_bit>::max(const Fixed<fractional_bit> &f1, const Fixed<fractional_bit> &f2)
{
	return ((f1 < f2) ? f2 : f1);
}

typedef Fixed<8> Fixed8_t;

#endif