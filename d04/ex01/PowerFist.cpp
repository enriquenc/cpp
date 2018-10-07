// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PowerFist.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 18:36:22 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 18:36:22 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PowerFist.hpp"

PowerFist::PowerFist(void): AWeapon("Power Fist", 50, 8){}

PowerFist::PowerFist(std::string const & name, int apcost, int damage): AWeapon(name , apcost, damage){}

PowerFist::~PowerFist(void){}

void PowerFist::attack(void) const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}