// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/04 09:52:18 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/04 09:52:19 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_raw_bits = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(n << getFractionalBits());
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(n * (1 << getFractionalBits())));
}

const int &Fixed::getFractionalBits(void) const
{
	return Fixed::_fractional_bits;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)getRawBits() / ( 1 << getFractionalBits()));
}

int Fixed::toInt(void) const
{
	return (getRawBits() >> getFractionalBits());
}

int Fixed::getRawBits(void) const
{
	return this->_raw_bits;
}

void Fixed::setRawBits(int const raw)
{
	this->_raw_bits = raw;
}

Fixed & Fixed::operator=(const Fixed & obj)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_raw_bits = obj.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & obj)
{
	o << obj.toFloat();
	return o;
}