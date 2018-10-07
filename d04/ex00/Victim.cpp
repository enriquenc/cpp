// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 14:55:19 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 14:55:20 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Victim.hpp"
#include <iostream>

Victim::Victim(void)
{

}

Victim::Victim(std::string const & name)
{
    _name = name;
    
    std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::Victim(Victim const & obj)
{
    *this = obj;
}

Victim::~Victim(void)
{
    std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
}

void Victim::getPolymorphed(void) const
{
    std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}

const std::string &Victim::getName(void) const
{
    return _name;
}

Victim & Victim::operator=(Victim const & obj)
{
    _name = obj._name;
    return *this;
}

std::ostream & operator<<(std::ostream & o, Victim & obj)
{
    o << "I'm " << obj.getName() << " and I like otters !" << std::endl;
    return o;
}

