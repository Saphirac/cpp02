/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 03:36:18 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/23 04:22:39 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:

	Fixed const	_x;
	Fixed const	_y;

public:

	Point();
	Point(Point const &src);
	Point(float const x, float const y);

	~Point();

	Fixed	x(void) const;
	Fixed	y(void) const;

	Point	&operator=(Point const &rhs);
};

std::ostream	&operator<<(std::ostream &o, Point const &rhs);

#endif
