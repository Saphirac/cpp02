/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:58:25 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/23 04:36:46 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const p);

int	main(void)
{
	Point	a(0.0f, 5.0f);
	Point	b(0.0f, 0.0f);
	Point	c(3.0f, 0.0f);
	Point	p(1.5f, 1.75f);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "p: " << p << std::endl;

	std::cout << "bsp(a, b, c, p): " << (bsp(a, b, c, p) ? "true" : "false") << std::endl;
	return  0;
}
