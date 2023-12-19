/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:34:21 by laugarci          #+#    #+#             */
/*   Updated: 2023/12/19 12:12:17 by laugarci         ###   ########.fr       */
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
		Fixed&	operator=(const Fixed& oldfix);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat (void) const;
		int toInt (void) const;
};

std::ostream&	operator<<( std::ostream& out, const Fixed& fixed );

#endif
