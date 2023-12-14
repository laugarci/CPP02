/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:01:02 by laugarci          #+#    #+#             */
/*   Updated: 2023/12/14 16:38:37 by laugarci         ###   ########.fr       */
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

Fixed::Fixed(Fixed& fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed& Fixed::operator=(Fixed& fix)
{
	std::cout << "Copy assigment operator called" << std::endl;
}

int	Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
}
