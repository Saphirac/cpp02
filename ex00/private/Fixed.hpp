/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:46:04 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/20 23:22:47 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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
	~Fixed();

	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	Fixed		&operator=(Fixed const &nb);

};

#endif
