/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:01:02 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/12 11:03:16 by laugarci         ###   ########.fr       */
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member called" << std::endl;
	this->_fixed = raw;
}
