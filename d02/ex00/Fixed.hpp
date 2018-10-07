// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/04 09:52:12 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/04 09:52:13 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int _raw_bits;
	static const int _fractional_bits;
public:
	Fixed(void);
	Fixed(const Fixed &obj);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed & operator=(const Fixed & obj);
};

#endif