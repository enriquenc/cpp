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
	this->_raw_bits = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
}

Fixed::Fixed(const int n)
{
	setRawBits(n << getFractionalBits());
}

Fixed::Fixed(const float n)
{
	setRawBits(roundf(n * (1 << getFractionalBits())));
}

const int &Fixed::getFractionalBits(void) const
{
	return Fixed::_fractional_bits;
}

Fixed::~Fixed(void)
{

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

Fixed Fixed::operator+(Fixed const & obj)const
{
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(Fixed const & obj)const
{
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(Fixed const & obj)const
{
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(Fixed const & obj)const
{
	return Fixed(this->toFloat() / obj.toFloat());
}

Fixed Fixed::operator%(Fixed const & obj) const
{
	return (this->toInt() % obj.toInt());
}

bool Fixed::operator==(Fixed const & obj)const
{
	return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator>(Fixed const & obj)const
{
	return (this->getRawBits() > obj.getRawBits());
}

bool Fixed::operator<(Fixed const & obj)const
{
	return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator<=(Fixed const & obj)const
{
	return (this->getRawBits() <= obj.getRawBits());
}

bool Fixed::operator>=(Fixed const & obj)const
{
	return (this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator!=(Fixed const & obj)const
{
	return (this->getRawBits() >= obj.getRawBits());
}

const Fixed &Fixed::operator++(void)
{
	this->setRawBits(getRawBits() + 1);
	return *this;
}

const Fixed &Fixed::operator++(int)
{
	++(*this);
	return *(this);
}

const Fixed &Fixed::operator--(void)
{
	this->setRawBits(getRawBits() - 1);
	return *this;
}

const Fixed &Fixed::operator--(int)
{
	--(*this);
	return *(this);
}

const Fixed &Fixed::min(Fixed const & obj1, Fixed const & obj2)
{
	if (obj1 < obj2)
		return (obj1);
	else
		return (obj2);
}

const Fixed &Fixed::max(Fixed const & obj1, Fixed const & obj2)
{
	if (obj1 > obj2)
		return (obj1);
	else
		return (obj2);
}

Fixed & Fixed::operator=(const Fixed & obj)
{
	this->_raw_bits = obj.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & obj)
{
	o << obj.toFloat();
	return o;
}