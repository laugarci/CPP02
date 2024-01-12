/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:34:21 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/12 11:01:35 by laugarci         ###   ########.fr       */
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
		~Fixed();
		Fixed(const Fixed& oldfix);
		Fixed&	operator=(const Fixed& oldfix);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
