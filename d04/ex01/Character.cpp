// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 19:29:20 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 19:29:21 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"

Character::Character(void): _name("noname"),
                        _action_points(40),
                        _weapon(NULL)
{}

Character::Character(std::string name): _name(name),
                                        _action_points(40),
                                        _weapon(NULL)
{
}

Character::Character(Character const & obj)
{
    *this = obj;
}

Character::~Character(void){}

Character & Character::operator=(Character const & obj)
{
    _name = obj._name;
    _action_points = obj._action_points;
    _weapon = obj._weapon;
    return *this;
}

void Character::recoverAP(void)
{
    if (_action_points + 10 < 40)
        _action_points += 10;
    else
        _action_points = 40;
}

void Character::equip(AWeapon *weapon)
{
    _weapon = weapon;
}

void Character::attack(Enemy *enemy)
{
    if(_weapon && (_action_points - _weapon->getAPCost()) >= 0)
    {
        std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
        _weapon->attack();
        enemy->takeDamage(_weapon->getDamage());
        _action_points -= _weapon->getAPCost();
        if (enemy->getHP() <= 0)
            delete enemy;
    }
}

std::string const & Character::getName(void) const
{
    return _name;
}

int const & Character::getAP(void) const
{
    return _action_points;
}

std::string Character::getWeaponName(void) const
{
    return _weapon->getName();
}

bool Character::weaponEquiped(void) const
{
    if (_weapon)
        return true;
    else
        return false;
}

std::ostream & operator<<(std::ostream & o, Character const & obj)
{
    if (obj.weaponEquiped())
        o << obj.getName() << " has " << obj.getAP() << " AP and wields a " << obj.getWeaponName() << std::endl;
    else
        o << obj.getName() << " has " << obj.getAP() << " AP and is unarmed" << std::endl;
    return o;
}