/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:34:21 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/10 16:53:11 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
	private:
		int _fixed;
		static const int _frac = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed& oldfix);
		//Comparison operators
		Fixed&	operator=(const Fixed& oldfix);
		bool	operator>(const Fixed& oldfix) const;
		bool	operator<(const Fixed& oldfix) const;
		bool	operator>=(const Fixed& oldfix) const;
		bool	operator<=(const Fixed& oldfix) const;
		bool	operator==(const Fixed& oldfix) const;
		bool	operator!=(const Fixed& oldfix) const;
		//Arithmetic operators
		Fixed	operator+(const Fixed& oldfix) const;
		Fixed	operator-(const Fixed& oldfix) const;
		Fixed	operator*(const Fixed& oldfix) const;
		Fixed	operator/(const Fixed& oldfix) const;
		//Increment/decrement operators
		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void); //done
		Fixed	operator--(int); //done
		//Overloaded member functions
		static Fixed&			min(Fixed& num1, Fixed& num2); //done
		static const Fixed&	min(const Fixed& num1, const Fixed& num2); //done
		static Fixed&			max(Fixed& num1, Fixed& num2); //done
		static const Fixed&	max(const Fixed& num1, const Fixed& num2); //done
		//Other functions
		int				getRawBits(void) const; //done
		void			setRawBits(int const raw); //done
		float 			toFloat (void) const; //done
		int 			toInt (void) const; //done
};

std::ostream&	operator<<( std::ostream& out, Fixed& fixp );
std::ostream&	operator<<( std::ostream& out, const Fixed& fixp );

#endif
