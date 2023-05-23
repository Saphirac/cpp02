/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:55:58 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/23 03:31:50 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

int const	Fixed::_bits(8);

// Constructors and Destructor //

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

// Getter and setter //

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

// toFloat and toInt //

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

// Min and Max //

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (DEBUG)
		std::cout << "max member function called\n";
	if (a > b)
		return a;
	return b;
}

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	if (DEBUG)
		std::cout << "min member function called\n";
	if (a < b)
		return a;
	return b;
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (DEBUG)
		std::cout << "max const member function called\n";
	if (a > b)
		return a;
	return b;
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (DEBUG)
		std::cout << "min const member function called\n";
	if (a < b)
		return a;
	return b;
}

// Operators //

Fixed	&Fixed::operator=(Fixed const &nb)
{
	if (DEBUG)
		std::cout << "Copy assignment operator called\n";
	if (this != &nb)
		this->_fix = nb.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout << "> operator called\n";
	return this->_fix > rhs._fix;
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout << "< operator called\n";
	return this->_fix < rhs._fix;
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout << ">= operator called\n";
	return this->_fix >= rhs._fix;
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout << "<= operator called\n";
	return this->_fix <= rhs._fix;
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout << "== operator called\n";
	return this->_fix == rhs._fix;
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout << "!= operator called\n";
	return this->_fix != rhs._fix;
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout << "+ operator called\n";
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout << "- operator called\n";
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout << "* operator called\n";
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	if (DEBUG)
		std::cout << "/ operator called\n";
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	Fixed::operator++(int)
{
	Fixed	n(*this);

	if (DEBUG)
		std::cout << "++ after operator called\n";
	++this->_fix;
	return n;
}

Fixed	Fixed::operator--(int)
{
	Fixed	n(*this);

	if (DEBUG)
		std::cout << "-- after operator called\n";
	--this->_fix;
	return n;
}

Fixed	&Fixed::operator++(void)
{
	if (DEBUG)
		std::cout << "++ before operator called\n";
	++this->_fix;
	return *this;
}

Fixed	&Fixed::operator--(void)
{
	if (DEBUG)
		std::cout << "-- before operator called\n";
	--this->_fix;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return	o;
}
