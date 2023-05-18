/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:46:04 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/17 19:54:59 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
private:

	int					fix;
	static int const	bits;

public:

	Fixed();
	~Fixed();

	int const	getRawBits( void ) const;
	void		setRawBits( int const raw );

};

#endif
