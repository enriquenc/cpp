// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 11:24:46 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/03 11:24:47 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon(void)
{
	
}

std::string &Weapon::getType(void)
{
    return this->type;
}

void Weapon::setType(const std::string type)
{
    this->type = type;
}


