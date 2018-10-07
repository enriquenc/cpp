// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Frog.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:13:05 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 17:13:06 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Frog.hpp"

Frog::Frog(void){}

Frog::Frog(std::string const & name) : Victim(name)
{
    _name = name;
    std::cout << "Qua Qua...." << std::endl;
}

Frog::~Frog(void)
{
    std::cout << "Hihihiihi..." << std::endl;
}

void Frog::getPolymorphed(void) const
{
    std::cout << _name << " has been turned into beautiful princes !" << std::endl;
}