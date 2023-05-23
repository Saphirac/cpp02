/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 03:56:07 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/23 04:31:53 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	__area(Point const a, Point const b, Point const c)
{
	return Fixed::abs((a.x() * (b.y() - c.y()) + b.x() * (c.y() - a.y()) + c.x() * (a.y() - b.y())) / Fixed(2.0f));
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed	area;
	Fixed	a1;
	Fixed	a2;
	Fixed	a3;

	area = __area(a, b, c);
	a1 = __area(a, b, p);
	a2 = __area(a, c, p);
	a3 = __area(b, c, p);

	return area == (a1 + a2 + a3);
}
