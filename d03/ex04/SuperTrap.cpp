// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 20:55:07 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/05 20:55:08 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SuperTrap.hpp"

SuperTrap::SuperTrap():		ClapTrap::ClapTrap(),
							NinjaTrap::NinjaTrap(),
							FragTrap::FragTrap()
							
{
	std::cout << "SuperTrap. Default constructor called." << std::endl;
}

SuperTrap::SuperTrap(std::string name):	ClapTrap(name),
										NinjaTrap(name),
										FragTrap(name)
										
{
	_hit_points = FragTrap::_hit_points;
	_max_hit_points = FragTrap::_max_hit_points;
	_energy_points = NinjaTrap::_energy_points;
	_max_energy_points = NinjaTrap::_max_energy_points;
	_level = 1;
	_name = name;
	_melee_attack_damage = NinjaTrap::_melee_attack_damage;
	_ranged_attack_damage = FragTrap::_ranged_attack_damage;
	_armor_damage_reduction = FragTrap::_armor_damage_reduction;
	std::cout << "SuperTrap. Constructor called. Name - " << this->_name << '.' << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap & obj)
{
	std::cout << "SuperTrap. Constructor called. Name - " << this->_name << '.' << std::endl;
	*this = obj;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SuperTrap. Destructor called. Name - " << _name << '.' << std::endl;
}

int SuperTrap::rangedAttack(const std::string &target)
{
	return(FragTrap::rangedAttack(target));
}

int SuperTrap::meleeAttack(const std::string &target)
{
	return(NinjaTrap::meleeAttack(target));
}

SuperTrap & SuperTrap::operator=(const SuperTrap & obj)
{
	_hit_points = obj._hit_points;
	_max_hit_points = obj._max_hit_points;
	_energy_points = obj._energy_points;
	_max_energy_points = obj._energy_points;
	_level = obj._level;
	_name = obj._name;
	_melee_attack_damage = obj._melee_attack_damage;
	_ranged_attack_damage = obj._ranged_attack_damage;
	_armor_damage_reduction = obj._armor_damage_reduction;
	
	_sleep = obj._sleep;
	return *this;
}