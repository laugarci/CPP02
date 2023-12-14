/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:34:21 by laugarci          #+#    #+#             */
/*   Updated: 2023/12/14 16:38:35 by laugarci         ###   ########.fr       */
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
		Fixed(Fixed& fix);
		Fixed&	operator=(Fixed& fix);
		int getRawBits(void);
		void setRawBits(int const raw);
};


#endif
