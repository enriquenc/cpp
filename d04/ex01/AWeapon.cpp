// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 18:17:32 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 18:17:33 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AWeapon.hpp"

AWeapon::AWeapon(void){}

AWeapon::AWeapon(std::string const & name, int damage, int apcost) :    _name(name),
                                                                        _damage(damage),
                                                                        _ap_cost(apcost)
{}

AWeapon::AWeapon(AWeapon const & obj)
{
    *this = obj;
}

AWeapon::~AWeapon(void){}

AWeapon & AWeapon::operator=(AWeapon const & obj)
{
    _name = obj._name;
    _damage = obj._damage;
    _ap_cost = obj._ap_cost;
    return *this;
}

std::string AWeapon::getName(void) const
{
    return _name;
}

int AWeapon::getAPCost(void) const
{
    return _ap_cost;
}

int AWeapon::getDamage(void) const
{
    return _damage;
}
