/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:53:17 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/12 12:26:12 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "MORE TESTS" << std::endl;
	Fixed c (60);
	a = 20;
	c = 900;
	std::cout << "a + b = " << a+b << std::endl;
	std::cout << "b + c = " << b+c << std::endl;
	std::cout << "c / b = " << c/b << std::endl;
	std::cout << "c / a = " << c/a << std::endl;
	std::cout << "a * b = " << a*b << std::endl;
	std::cout << Fixed::min(a, c) << std::endl;

	return 0;
}
