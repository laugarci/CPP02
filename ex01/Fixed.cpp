/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:01:02 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/11 11:35:30 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = num << _frac;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(num * (1 << this->_frac));
}

Fixed::Fixed(const Fixed& oldfix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = oldfix;
}

Fixed& Fixed::operator=(const Fixed& oldfix)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &oldfix)
		this->_fixed = oldfix.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member called" << std::endl;
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

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
