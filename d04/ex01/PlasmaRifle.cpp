// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 18:36:22 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 18:36:22 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void): AWeapon("Plasma Rifle", 21, 5){};

PlasmaRifle::PlasmaRifle(std::string const & name, int apcost, int damage): AWeapon(name , apcost, damage){}

PlasmaRifle::~PlasmaRifle(void){}

void PlasmaRifle::attack(void) const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}