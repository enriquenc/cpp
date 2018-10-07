// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 19:29:24 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 19:29:25 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include "Enemy.hpp"
#include "AWeapon.hpp"

class Character
{
private:

    std::string _name;
    int _action_points;
    AWeapon *_weapon;

public:

    Character(void);
    Character(std::string name);
    Character(Character const & obj);
    ~Character(void);
    Character & operator=(Character const & obj);
    
    void recoverAP(void);
    void equip(AWeapon *weapon);
    void attack(Enemy *enemy);
    std::string const & getName(void) const;
    
    int const & getAP(void) const;
    std::string getWeaponName(void) const;
    bool weaponEquiped(void) const;
};

std::ostream & operator<<(std::ostream & o, Character const & obj);

#endif