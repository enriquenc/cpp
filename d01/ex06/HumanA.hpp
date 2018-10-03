// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 11:25:07 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/03 11:25:08 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    Weapon *weapon;
    std::string name;
public:
    HumanA(std::string name, Weapon &weapon);

    void attack(void);
    void setWeapon(Weapon &weapon);
};

#endif