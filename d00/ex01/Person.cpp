// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Person.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/01 14:04:50 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/01 14:04:51 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Person.hpp"

Person::Person(void)
{
	Person::nbInst += 1;
}

Person::~Person(void)
{
	Person::nbInst -= 1;
}

int Person::nbInst = 0;

int Person::getNbInst(void)
{
	return Person::nbInst;
}

void Person::setFirst_name(const std::string &first_name)
{
	this->first_name = first_name;
}
void Person::setLast_name(const std::string &last_name)
{
	this->last_name = last_name;
}
void Person::setNickname(const std::string &nickname){
	this->nickname = nickname;
}
void Person::setLogin(const std::string &login)
{
	this->login = login;
}
void Person::setPostal_address(const std::string &postal_address)
{
	this->postal_address = postal_address;
}
void Person::setEmail_address(const std::string &email_address)
{
	this->email_address = email_address;
}
void Person::setPhone_number(const std::string &phone_number)
{
	this->phone_number = phone_number;
}
void Person::setBirthday_date(const std::string &birthday_date)
{
	this->birthday_date = birthday_date;
}
void Person::setFavorite_meal(const std::string &favorite_meal)
{
	this->favorite_meal = favorite_meal;
}
void Person::setUnderwear_color(const std::string &underwear_color)
{
	this->underwear_color = underwear_color;
}
void Person::setDarkest_secret(const std::string &darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

const std::string &Person::getFirst_name(void) const
{
	return this->first_name;
}
const std::string &Person::getLast_name(void) const
{
	return this->last_name;
}
const std::string &Person::getNickname(void) const
{
	return this->nickname;
}
const std::string &Person::getLogin(void) const
{
	return this->login;
}
const std::string &Person::getPostal_address(void) const
{
	return this->postal_address;
}
const std::string &Person::getEmail_adress(void) const
{
	return this->email_address;
}
const std::string &Person::getPhone_number(void) const
{
	return this->phone_number;
}
const std::string &Person::getBirthday_date(void) const
{
	return this->birthday_date;
}
const std::string &Person::getFavorite_meal(void) const
{
	return this->favorite_meal;
}
const std::string &Person::getUnderwear_color(void) const
{
	return this->underwear_color;
}
const std::string &Person::getDarkest_secret(void) const
{
	return this->darkest_secret;
}