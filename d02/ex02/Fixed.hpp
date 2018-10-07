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

#include <iostream>

class Fixed
{
private:
	int _raw_bits;
	static const int _fractional_bits;
public:
	Fixed(void);
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &obj);
	~Fixed(void);

	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

	const int &getFractionalBits(void) const;

	Fixed operator+(Fixed const & obj) const;
	Fixed operator-(Fixed const & obj) const;
	Fixed operator*(Fixed const & obj) const;
	Fixed operator/(Fixed const & obj) const;
	bool  operator==(Fixed const & obj) const;
	bool  operator>(Fixed const & obj)const;
	bool  operator<(Fixed const & obj)const;
	bool  operator<=(Fixed const & obj)const;
	bool  operator>=(Fixed const & obj)const;
	bool  operator!=(Fixed const & obj)const;
	const Fixed &operator++(void);
	const Fixed &operator++(int);
	const Fixed &operator--(void);
	const Fixed &operator--(int);

	static const Fixed &min(Fixed const & obj1, Fixed const & obj2);
	static const Fixed &max(Fixed const & obj1, Fixed const & obj2);
	static Fixed &min(Fixed & obj1, Fixed & obj2);
	static Fixed &max(Fixed & obj1, Fixed & obj2);
	
	Fixed & operator=(const Fixed & obj);
};

std::ostream & operator<<(std::ostream & o, Fixed const & obj);

#endif