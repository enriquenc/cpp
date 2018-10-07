// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Virgin.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:13:05 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 17:13:06 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Virgin.hpp"

Virgin::Virgin(void) {}

Virgin::Virgin(std::string const & name) : Victim(name)
{
    _name = name;
    std::cout << "Oh no, i will die virgin!" << std::endl;
}

Virgin::~Virgin(void)
{
    std::cout << "Goodbye my lover..." << std::endl;
}

void Virgin::getPolymorphed(void) const
{
    std::cout << _name << " has been turned into old granny !" << std::endl;
}