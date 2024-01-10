/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:01:02 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/10 17:39:30 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructor
Fixed::Fixed()
{
	this->_fixed = 0;
}

//Destructor
Fixed::~Fixed()
{
}

//Int constructor. Convierte un numero entero en un fixed-point number. La parte fraccionaria se rellena de ceros.
Fixed::Fixed(const int num)
{
	this->_fixed = num << _frac; 
}

//Constructor de copia. Inicializa otro objeto con los mismos valores que otro objeto Fixed
Fixed::Fixed(const Fixed& oldfix)
{
	*this = oldfix;
}

//Fload constuctor. Convierte un float en un fixed-point number. Hace una operacion de redondeo para representar la parte fraccionaria
Fixed::Fixed(const float num)
{
	this->_fixed = roundf(num * (1 << _frac));
}

//Operador de copia. Asigna los valores de otro objeto Fixed al actual
Fixed& Fixed::operator=(const Fixed& oldfix)
{
	if (this != &oldfix)
		this->_fixed = oldfix.getRawBits();
	return (*this);
}

//Comparison operators
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

//Convierte el fixed-point number a float
float	Fixed::toFloat() const
{
	return (this->_fixed / (float)(1 << _frac));
}

//Convierte el fixed-point number a int
int		Fixed::toInt(void) const
{
	return (this->_fixed >> _frac);
}

//Devuelve el numero mas pequeno
const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	return (num1 < num2 ? num1 : num2);
}

//Devuelve el numero mas pequeno
Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	return (num1 < num2 ? num1 : num2);
}

//Devuelve el numero mas grande
const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2)
{
	std::cout << "const" << std::endl;
	return (num1 > num2 ? num1 : num2);
}

//Devuelve el numero mas grande
Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	std::cout << "no const" << std::endl;
	return (num1 > num2 ? num1 : num2);
}

// Operator: Output
std::ostream&	operator<<( std::ostream& out, Fixed& fixp )
{
	out << fixp.toFloat();
	return (out);
}

// Operator: Constant: Output
std::ostream&	operator<<( std::ostream& out, const Fixed& fixp )
{
	out << fixp.toFloat();
	return (out);
}
