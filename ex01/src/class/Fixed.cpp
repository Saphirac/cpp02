/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:55:58 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/23 03:00:23 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

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

Fixed::Fixed(int const nb) :
_fix(nb << _bits)
{
	if (DEBUG)
		std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const nb) :
_fix((int)roundf(nb * (1 << _bits)))
{
	if (DEBUG)
		std::cout << "Float constructor called\n";
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

float		Fixed::toFloat(void) const
{
	if (DEBUG)
		std::cout << "toFloat member function called\n";
	return (float)this->_fix / (1 << Fixed::_bits);
}

int			Fixed::toInt(void) const
{
	if (DEBUG)
		std::cout << "toInt member function called\n";
	return this->_fix >> Fixed::_bits;
}

Fixed	&Fixed::operator=(Fixed const &nb)
{
	if (DEBUG)
		std::cout << "Copy assignment operator called\n";
	if (this != &nb)
		this->_fix = nb.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return	o;
}
