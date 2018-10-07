// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 14:55:13 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 14:55:13 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Sorcerer.hpp"
#include <iostream>


Sorcerer::Sorcerer(std::string const & name, std::string const & title)
{
    _name = name;
    _title = title;
    std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & obj)
{
    *this = obj;
}

Sorcerer::~Sorcerer(void)
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

void Sorcerer::polymorph(Victim const & obj) const
{
    obj.getPolymorphed();
}

const std::string & Sorcerer::getName(void) const
{
    return _name;
}

const std::string & Sorcerer::getTitle(void) const
{
    return _title;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & obj)
{
    _name = obj._name;
    _title = obj._title;
    return *this;
}

std::ostream & operator<<(std::ostream & o, Sorcerer & obj)
{
    o << "I am " << obj.getName() << ", " << obj.getTitle() << ", and I like ponies !" << std::endl;
    return o;
}
