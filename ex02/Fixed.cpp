/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:01:02 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/24 10:38:10 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixed = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int num)
{
	this->_fixed = num << _frac; 
}

Fixed::Fixed(const Fixed& oldfix)
{
	*this = oldfix;
}

Fixed::Fixed(const float num)
{
	this->_fixed = roundf(num * (1 << _frac));
}

//Comparison operators
Fixed& Fixed::operator=(const Fixed& oldfix)
{
	if (this != &oldfix)
		this->_fixed = oldfix.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed& oldfix) const
{
	return (this->_fixed > oldfix.getRawBits());
}

bool Fixed::operator<(const Fixed& oldfix) const
{
	return (this->_fixed < oldfix.getRawBits());
}

bool	Fixed::operator>=(const Fixed& oldfix) const
{
	return (this->_fixed >= oldfix.getRawBits());
}

bool	Fixed::operator<=(const Fixed& oldfix) const
{
	return (this->_fixed <= oldfix.getRawBits());
}

bool	Fixed::operator==( const Fixed &oldfix ) const
{
	return ( this->_fixed == oldfix.getRawBits() );
}

bool	Fixed::operator!=( const Fixed &oldfix ) const
{
	return ( this->_fixed != oldfix.getRawBits() );
}

//Arithmetic operators
Fixed Fixed::operator+(const Fixed& oldfix) const
{
	return (this->toFloat() + oldfix.toFloat());
}

Fixed Fixed::operator-(const Fixed& oldfix) const
{
	return (this->toFloat() - oldfix.toFloat());
}

Fixed Fixed::operator*(const Fixed& oldfix) const
{
	return (this->toFloat() * oldfix.toFloat());
}

Fixed Fixed::operator/(const Fixed& oldfix) const
{
	return (this->toFloat() / oldfix.toFloat());
}

//Increment/decrement operators
Fixed Fixed::operator++(void)
{
	this->_fixed++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed pre(*this);
	this->_fixed++;
	return (pre);
}

Fixed Fixed::operator--(void)
{
	this->_fixed--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed pre(*this);
	this->_fixed--;
	return (pre);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

float	Fixed::toFloat() const
{
	return (this->_fixed / (float)(1 << _frac));
}

int		Fixed::toInt(void) const
{
	return (this->_fixed >> _frac);
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	return (num1 < num2 ? num1 : num2);
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	return (num1 < num2 ? num1 : num2);
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2)
{
	return (num1 > num2 ? num1 : num2);
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	return (num1 > num2 ? num1 : num2);
}

std::ostream&	operator<<( std::ostream& out, Fixed& fixp )
{
	out << fixp.toFloat();
	return (out);
}

std::ostream&	operator<<( std::ostream& out, const Fixed& fixp )
{
	out << fixp.toFloat();
	return (out);
}
