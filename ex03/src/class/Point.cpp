/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 03:38:31 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/23 04:20:48 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() :
_x(Fixed(0)),
_y(Fixed(0))
{
	if (DEBUG)
		std::cout << "Constructor called\n";
}

Point::Point(Point const &src) :
_x(src._x),
_y(src._y)
{
	if (DEBUG)
		std::cout << "Copy constructor called\n";
}

Point::Point(float const x, float const y) :
_x(Fixed(x)),
_y(Fixed(y))
{
	if (DEBUG)
		std::cout << "Constructor called\n";
}

Point::~Point()
{
	if (DEBUG)
		std::cout << "Destructor called\n";
}

Fixed	Point::x(void) const
{
	if (DEBUG)
		std::cout << "x getter called\n";
	return this->_x;
}
	
Fixed	Point::y(void) const
{
	if (DEBUG)
		std::cout << "y getter called\n";
	return this->_y;
}

Point	&Point::operator=(Point const &rhs)
{
	if (DEBUG)
		std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
	{
		*(Fixed *)&this->_x = rhs._x;
		*(Fixed *)&this->_y = rhs._y;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Point const &rhs)
{
	o << "{" << rhs.x() << ", " << rhs.y() << "}";
	return o;
}
