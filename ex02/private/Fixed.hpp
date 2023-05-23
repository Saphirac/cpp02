/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:46:04 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/23 03:39:54 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Fixed {
private:

	int					_fix;
	static int const	_bits;

public:

	Fixed();
	Fixed(Fixed const &src);
	Fixed(int const nb);
	Fixed(float const nb);
	~Fixed();

	int			getRawBits(void) const;
	void		setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed		&max(Fixed &a, Fixed &b);
	static Fixed		&min(Fixed &a, Fixed &b);
	static Fixed const	&max(Fixed const &a, Fixed const &b);
	static Fixed const	&min(Fixed const &a, Fixed const &b);

	Fixed		&operator=(Fixed const &nb);

	bool	operator>(Fixed const &rhs) const;
	bool	operator<(Fixed const &rhs) const;
	bool	operator>=(Fixed const &rhs) const;
	bool	operator<=(Fixed const &rhs) const;
	bool	operator==(Fixed const &rhs) const;
	bool	operator!=(Fixed const &rhs) const;
	Fixed	operator+(Fixed const &rhs) const;
	Fixed	operator-(Fixed const &rhs) const;
	Fixed	operator*(Fixed const &rhs) const;
	Fixed	operator/(Fixed const &rhs) const;

	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed	&operator++(void);
	Fixed	&operator--(void);
	
};

std::ostream	&operator<<(std::ostream &obj, Fixed const &nb);

#endif
