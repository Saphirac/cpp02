/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:55:58 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/20 23:22:30 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int const	Fixed::_bits(8);

Fixed::Fixed(void) :
_fix(0)
{
	if (DEBUG)
		std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &src) :
_fix(src._fix)
{
	if (DEBUG)
		std::cout << "Copy constructor called\n";
}

Fixed::~Fixed(void)
{
	if (DEBUG)
		std::cout << "Destructor called\n";
}

int			Fixed::getRawBits(void) const
{
	if (DEBUG)
		std::cout << "getRawBits member function called\n";
	return this->_fix;
}

void		Fixed::setRawBits(int const raw)
{
	if (DEBUG)
		std::cout << "setRawBits member function called\n";
	this->_fix = raw;
}

Fixed	&Fixed::operator=(Fixed const &nb)
{
	if (DEBUG)
		std::cout << "Copy assignment operator called\n";
	if (this != &nb)
		this->_fix = nb.getRawBits();
	return *this;
}
