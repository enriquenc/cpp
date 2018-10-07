// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 18:17:36 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 18:17:37 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <string>
#include <iostream>

class AWeapon
{
private:

    std::string _name;
    int _damage;
    int _ap_cost;

public:

    AWeapon(void);
    AWeapon(std::string const &name, int apcost, int damage);
    AWeapon(AWeapon const & obj);
    virtual ~AWeapon(void);

    AWeapon & operator=(AWeapon const & obj);

    std::string virtual getName(void) const;
    int getAPCost(void) const;
    int getDamage(void) const;
    virtual void attack(void) const = 0;
};

#endif