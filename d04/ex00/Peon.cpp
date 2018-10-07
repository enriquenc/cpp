// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 14:55:40 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 14:55:41 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Peon.hpp"
#include <iostream>

Peon::Peon(void){}

Peon::Peon(std::string const & name) : Victim(name)
{
    _name = name;
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void)
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed(void) const
{
    std::cout << _name << " has been turned into a pink pony !" << std::endl; 
}
